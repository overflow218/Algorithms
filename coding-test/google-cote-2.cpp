#include <iostream>
#include <climits>
using namespace std;

/*
구글 코테 2번째 문제
서버의 개수 N개 (N <= 10 ^ 5)가 주어지고 
다음에 A[], B[] 각각 N개의 정수가 담긴 배열이 주어짐. A[i], B[i] <= 10^9 -> long long 필요함.
각 서버는 혼자 microservice로 활용되거나 같이 묶여서 monolith 로 사용될 수 있음. 
i번 서버가 마이크로 서비스로 혼자 사용될때의 비용이 A[i]에 담겨있고 
monolith 로 같이 사용될때의 비용이 B[i]에 담겨있음. 
단 묶여서 사용되려면 최소 그룹에 2개이상의 서버가 있어야하고, 
인접한 서버랑만 묶일 수 있음. (바로 옆에가 monolith여야한다는 소리)
이럴때 서버를 구축하는 최소비용을 구하는 문제
*/
int a[100000], b[100000], n;
// 필요하다면 부분합 구하는게 좋을듯

/*
아래와 같이 작성하게 되면 시간복잡도가 O(n^2)가 되어버림. n이 10만이라서 절대 시간안에 못들어옴
*/
int find(int s, int e)
{
    // 둘일때는 붙이든지 따로 따로 하든지 바로 정하면 됨
    if(e - s == 1)
    {
        return min(a[s] + a[e], b[s] + b[e]);
    }

    int ret = 0;
    for(int i = s + 1; i < e; i++)
    {
        //i 번째만 혼자 띄어낸다고 생각
        int tmp = find(s, i - 1) + a[i] + find(i + 1, e);
        ret = min(tmp, ret);
    }
    ret = min(ret, a[s] + find(s + 1, e));
    ret = min(ret, a[e] + find(s, e - 1));
    return ret;
}

long long cache[2][100000];

// idx는 현재 시작위치, isMonolith는 직전의 서버가 Monolith인지 여부를 나타낸다.
// 0이면 아닌거, 1이면 monolith
long long find2(int idx, int isMonolith)
{
    /*
    여기서 idx번이 선택할 수 있는거는 
    1. 앞에까지가 monolith이지만 여기서 그냥 microservice로 가본다     
    2. 앞에까지가 모노리스이니까 같이 붙어서 간다
    3. 앞에가 모노리스 아니지만 여기서부터 시작해본다. 
    */
   if(idx == n) return 0;
   long long &ret = cache[isMonolith][idx];
   // cache해서 해결할 수 있을듯
   if(ret != 0) return ret;
   ret = numeric_limits<long long>::max(); // 엄청 큰수 넣어주기

    // 1. 그냥 microservice로 가본다  
   ret = min(ret, a[idx] + find2(idx + 1, 0));
   // 2. 만약에 앞에가 monolith라면 이어서가본다
   if(isMonolith == 1)
   {
        ret = min(ret, b[idx] + find2(idx + 1, 1));
   }

   // 앞에가 monolith가 아니지만 여기서부터 monolith를 시작해본다 무조건 한칸 뒤의 서버는 같이 묶어서 들어가줘야함.
   if(isMonolith == 0 && idx <= n - 2)
   {
        ret = min(ret, b[idx] + b[idx + 1] + find2(idx + 2, true));
   }
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    long long ans = find2(0, 0);
    cout << ans << '\n';
    return 0;
}
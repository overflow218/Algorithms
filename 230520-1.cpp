#include <string>
#include <vector>
using namespace std;

/*
0단계
1
1단계
11011
2단계
(11011)(11011)(00000)(11011)(11011)
3단계
((11011)(11011)(00000)(11011)(11011))((11011)(11011)(00000)(11011)(11011))(0이 25개)((11011)(11011)(00000)(11011)(11011))((11011)(11011)(00000)(11011)(11011))

대충 이런느낌이란 말이지
0단계 1개 -> 1단계 5개 -> 2단계 25개 ... n단계는 총 5 ^ n개의 수가 존재함. 
1의 개수는
0단계 1개 -> 1단계 4개 -> 2단계 16개 ... 총 4 ^ n개의 수가 존재함.

이거 범위로 하는게 어렵다면 그냥 x번째께 1인지 아닌지를 판단하는 것도 나쁘지 않음. 
그걸 빠르게 구할 수 있으면 1천만번 돌리면 된단말이지. 
find(n, x) n단계에서 x번째수가 1이면 1리턴, 아니면 0 리턴
이때는 5 ^ (n - 1) 승을 미리 계산해두고 작거나 같을때까지 반복해야겠구먼..
그래서 n == 1일때 바로 찾아주면 되는거 아님?
n이 20이니까 매 재귀탐색에 20번만 타고 들어가면 된다는거고 
대충 20번 * 1천만번이면 2억이 넘지만, 코드 구조가 간단하니까 시간안에 해결 될거같은데 
*/
long long counter[21] = {1ll};
int find(int n, long long x)
{
    if(n == 1) return x != 3 ? 1 : 0;
    long long cnt = 0;
    long long add = counter[n - 1];
    for(int i = 1; i <= 5; i++)
    {
        if(x <= cnt + add) return i == 3 ? 0 : find(n - 1, x - cnt);
        cnt += add;
    }
}

int solution(int n, long long l, long long r) {
    int ans = 0;
    for(int i = 1; i <= 20; i++)
    {
        counter[i] = 5ll * counter[i - 1];
        printf("counter[%d] -> %lld\n", i, counter[i]);
    }
    for(long long i = l; i <= r; i++)
    {
        ans += find(n, i);
    }
    return ans;
}
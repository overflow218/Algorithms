#include <cstdio>
#include <iostream>
using namespace std;

long long ans[100][21] = {0};

int main()
{
  int n;
  int arr[100] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  int target = arr[n - 1];
  ans[0][arr[0]] = 1;
  for(int i = 1; i <= n - 2; i++)
  {
    for(int j = 0; j < 21; j++)
    {
      if(ans[i-1][j] != 0)
      {
        if(j + arr[i] <= 20)
        {
          ans[i][j + arr[i]] += ans[i-1][j];
        }
        if(j - arr[i] >= 0)
        {
          ans[i][j - arr[i]] += ans[i-1][j];
        }
      }
    }
  }
  printf("%lld\n", ans[n-2][target]);
  return 0;
}

/*
일단 지금 deque에 넣어서 풀었는데, 
정답으로 가능한 갯수가 너무 많아서 메모리 초과가 뜬다. 
덱으로 풀때는 이런거좀 생각하고 풀자. 
그럼 당연히 배열로 풀어야한다는 소리네. 

중간에 가질수 있는 값의 범위가 0 ~ 20 으로 한정되어 있으니 
배열을 만들기가 편하다. 
이걸로 배열을 만들어서 중간에 0 ~ 20 까지의 숫자가 몇개가 나오는지 
추적해가면 간단하게 풀 수 있다.

*/

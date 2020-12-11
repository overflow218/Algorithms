#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;


long long ans[500][500];
long long arr[500];

long long find(int start, int end);
long long partialSum(int start, int end);

int main()
{
  int t, k;
  scanf("%d", &t);
  for(int h = 0; h < t; h++)
  {
    // 배열 초기화 부분. 
    for(int i = 0; i < 500; i++)
    {
      for(int j = 0; j < 500; j++)
      {
        ans[i][j] = 0;
      }
      arr[i] = 0;
    }
    
    scanf("%d", &k);
    long long tmp;
    for(int i = 0; i < k; i++)
    {
      scanf("%lld", &arr[i]);
    }
    find(0, k-1);
    printf("%lld\n", ans[0][k-1]);
  }
  return 0;
}

long long find(int start, int end)
{
  if(ans[start][end] != 0)
  {
    return ans[start][end];
  } else if(start == end)
  {
    ans[start][end] = 0;
    return 0;
  } else if(start + 1 == end)
  {
    ans[start][end] = arr[start] + arr[end];
    return ans[start][end];
  } else 
  {
    long long tmp = LLONG_MAX;
    long long psum = partialSum(start, end);
    for(int i = start; i < end; i++)
    {
      tmp = min(tmp, find(start, i) + find(i + 1, end) + psum);
    }
    ans[start][end] = tmp;
    return tmp;
  }
}

long long partialSum(int start, int end)
{
  long long tmp = 0;
  for(int i = start; i <= end; i++)
  {
    tmp += arr[i];
  }
  return tmp;
}

/*
몰라서 답봤는데 좋았다.
이렇게도 풀 수 있구나 느꼈고, 다시 생각해보게 되었음. 
또한 1시간 넘게 못푸는건 그냥 죽었다 깨어나도 못푸니깐 
답보고 이해하고 내 방식으로 다시 풀어보는게 더 좋은 공부방법인것 같다. 
힘내자 형진아.
*/

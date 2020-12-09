#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  long long x, y, z, ans;

  scanf("%lld %lld", &x, &y);
  z = y * 100 / x;
  if(z >= 99)
  {
    ans = -1;
    // 저기선 더이상 확률 못올림. 
  } else 
  {
    long long start = 1;
    long long end = 1000000000;
    long long mid;
    while(start < end)
    {
      mid = (start + end) / 2;
      if((y + mid) * 100 / (x + mid) > z)
      {
        ans = mid;
        end = mid - 1;
      } else 
      {
        start = mid + 1;
      }
    }
    if((y + start) * 100 / (x + start) > z)
    {
      ans = start;
    }
  }
  printf("%lld\n", ans);
  return 0;
}

/*
시간제한이 2초고 최대크기가 10억밖에 안돼서 그냥 O(n)으로 풀어도 될줄알고 해봤는데, 
시간초과 난다. 이분탐색으로 푸니 금방 끝낼 수 있었땅. 끝

*/

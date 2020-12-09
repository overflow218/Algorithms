#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  long long s;
  scanf("%lld", &s);
  long long start = 1;
  long long idx = 1;
  long long sum = 0;
  long long ans = 0;
  while(sum + idx <= s)
  {
    sum += idx;
    ans++;
    idx++;
  }
  printf("%lld\n", ans);
  return 0;
}

/*
이분탐색 안쓰는게 더 빠름
*/

#include <cstdio>

int main()
{
  int l, p, v;
  int idx = 0;
  while(true)
  {
    idx++;
    scanf("%d %d %d", &l, &p, &v);
    if((l == 0 && p == 0) && v == 0)
    {
      break;
    }
    int ans = 0;
    ans += v / p * l;
    int tmp = v % p > l ? l : v % p;
    ans += tmp;
    printf("Case %d: %d\n", idx, ans);
  }
  return 0;
}
/*
출력 형식이 다른 문제들이랑 다른걸 간과하고 풀었다가 한번 틀렸다.
마음이 아프다..
*/

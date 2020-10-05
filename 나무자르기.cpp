#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cut(int * arr, int bottom, int top, int n, int m);

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int * arr = new int [n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  int top = arr[n - 1];
  int ans = cut(arr, 0, top, n, m);
  printf("%d\n", ans);
  return 0;
}

int cut(int * arr, int bottom, int top, int n, int m)
{
  long long b = bottom;
  long long t = top;
  int height;
  long long avg = (b + t) / 2;
  while(b <= t)
  {
    long long tmp = 0;
    for(int i = 0; i < n; i++)
    {
      int x = arr[i] - avg;
      x = x > 0 ? x : 0;
      tmp += x; 
    }

    if(tmp >= m) // 필요이상으로 많이 베어낸거니까 높이를 올릴 필요가 있음
    {
      height = avg;
      b = avg + 1;
    } else // 아직 부족하니까 높이를 낮출 필요가 있음. 
    {
      t = avg - 1;
    }
    avg = (b + t) / 2;
  }
  return height;
}
/*
요전의 랜선자르기와 비슷한 문제라 금방 해결할 수 있었다.
/*

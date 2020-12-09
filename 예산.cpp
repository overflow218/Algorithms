#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  int n, total; // 10억이 최대라 int로 충분
  int ans = 0;
  int start = 1;
  int end = 0;
  int big = 0;
  int mid;
  scanf("%d", &n);
  int * arr = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    if(arr[i] > end)
    {
      end = arr[i];
    }
  }
  scanf("%d", &total);

  while(start < end)
  {
    mid = (start + end) / 2;
    int tmp = 0; 
    for(int i = 0; i < n; i++)
    {
      if(arr[i] <= mid)
      {
        tmp += arr[i];
      } else  // 상한액보다 크면 상한액 만큼만 넣어야함. 
      {
        tmp += mid;
      } 
    }
    if (tmp <= total && tmp >= big)
    {
      ans = mid;
      big = tmp;
      start = mid + 1;
    } else 
    {
      end = mid - 1;
    }
  }
  int tmp = 0;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] <= start)
    {
      tmp += arr[i];
    } else 
    {
      tmp += start;
    }
  }
  if(tmp <= total && tmp >= big)
  {
    ans = start;
  }
  printf("%d\n", ans);
  return 0;
}

/*
이분탐색 연습중입니다.
*/

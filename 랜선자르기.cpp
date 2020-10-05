#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long find(int * arr, int small, int big, int k, int n);

int main()
{
  int k, n;
  long long ans;
  scanf("%d %d", &k, &n);

  int * arr = new int[k];
  for(int i = 0; i < k; i++)
  {
    scanf("%d", &arr[i]);
  }
  int x = arr[0];
  for(int i = 0; i < k; i++)
  {
    if(arr[i] > x)
    {
      x = arr[i];
    }
  }
  ans = find(arr, 1, x, k, n);
  printf("%lld", ans);
  return 0;
}

long long find(int * arr, int small, int big, int k, int n)
{
  long long s = small;
  long long b = big;
  long long avg = (s + b) / 2;
  int ans = 1;
  while(s <= b)
  {
    int count = 0; // 자른 선 갯수
    for(int i = 0; i < k; i++)
    {
      count += (arr[i] / avg);
    }

    if(count < n) // 자른 선 갯수가 목표치보다 작으면, b를 줄여서 평균을 낮춰야함.
    {
      b = avg - 1;
    } else  // 자른 선 갯수가 목표치보다 많거나 같다면, s를 키워서 평균을 올려야함. 
    {
      s = avg + 1;
      ans = avg;
    }
    avg = (s + b) / 2;

  }
  return ans;
}

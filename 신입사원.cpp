#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int * a, int * b);

int main()
{
  int t, n;
  scanf("%d", &t);
  for(int h = 0; h < t; h++)
  {
    scanf("%d", &n);
    int ** arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
      arr[i] = new int[2];
      scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    sort(arr, arr + n, cmp);
    int ans = n;
    for(int i = 1; i < n; i++)
    {
      if(arr[i][1] > arr[i-1][1])
      {
        ans--;
        arr[i][1] = arr[i-1][1];
      }
    }

    for(int i = 0; i < n; i++)
    {
      delete[] arr[i];
    }
    delete[] arr;
    printf("%d\n", ans);
  }
  return 0;
}

bool cmp(int * a, int *b)
{
  if(a[0] < b[0])
  {
    return true;
  }
  return false;
}

/*
서류 점수로 정렬해놓고, 
면접시험이 본인의 서류점수보다 높은 사람들보다 높으면 합격
아니면 탈락
*/

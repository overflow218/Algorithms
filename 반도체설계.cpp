#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int * arr = new int[n];
  int cnt = 0;
  int tmp;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &tmp);
    if(cnt == 0)
    {
      arr[cnt++] = tmp;
    } else 
    {
      if(arr[cnt - 1] < tmp)
      {
        arr[cnt++] = tmp;
      } else // 탐색을 해야 합니다. 
      {
        int start = 0;
        int end = cnt - 1;
        while(start < end)
        {
          int mid = (start + end) / 2;
          if(arr[mid] == tmp)
          {
            break;
          } else if(arr[mid] < tmp)
          {
            start = mid + 1;
          } else // arr[mid] > tmp
          {
            end = mid - 1;
          }
        }
        if(arr[start] < tmp)
        {
          start++;
        }
        arr[start] = tmp;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}

/*
이분탐색 문제. 
내용을 숨겨놔서 그렇지 
전에 풀어봤던 LCS(longes common sequence 문제와 유사
*/

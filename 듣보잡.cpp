#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

void find(int start, int end, string *&arr1, string *&arr2, string target);

int cnt = 0;

int main()
{
  char tmp[30];
  int n, m;
  scanf("%d %d", &n, &m);
  string * arr1 = new string [n];
  string * arr2 = new string [m];
  for(int i = 0; i < n ; i++)
  {
    scanf("%s", tmp);
    string x = tmp;
    arr1[i] = x;
  }
  sort(arr1, arr1 + n);
  for(int i = 0; i < m; i++)
  {
    scanf("%s", tmp);
    find(0, n - 1, arr1, arr2, tmp);
  }

  printf("%d\n", cnt);
  sort(arr2, arr2 + cnt);
  for(int i = 0; i < cnt; i++)
  {
    printf("%s\n", arr2[i].c_str());
  }
  return 0;
}

void find(int start, int end, string *&arr1,  string *&arr2, string target)
{
  if(start >= end)
  {
    if(arr1[start] == target)
    {
      arr2[cnt++] = target;
    }
  } else 
  {
    int mid = (start + end) / 2;
    if(arr1[mid] == target)
    {
      arr2[cnt++] = target;
      return;
    } else if(arr1[mid] < target)
    {
      start = mid + 1;
      return find(start, end, arr1, arr2, target);
    } else // arr1[mid] > target
    {
      end = mid - 1;
      return find(start, end, arr1, arr2, target);
    }
  }
}

/*
이분탐색 연습중...
*/

#include <cstdio>
#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int stat[20][20] = {0};
int small = -1;

void ans(deque<int> number, deque<int> link, int n);

int main()
{
  deque <int> number;
  deque <int> link;
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      scanf("%d", &stat[i][j]);
    }
  }

  for(int i = 0; i < n; i++)
  {
    number.push_back(i);
  }

  ans(number, link, n);
  printf("%d\n", small);
  return 0;
}

void ans(deque<int> number, deque<int> link, int n)
{
  if(link.size() == n / 2)
  {
    int len = n / 2;
    int sum_start = 0;
    int sum_link = 0;
    int arr[20] = {0};
    deque <int> start;
    for(int i = 0; i < len; i++)
    {
      arr[link[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
      if(arr[i] == 0)
      {
        start.push_back(i);
      }
    }
    for(int i = 0; i < len; i++)
    {
      for(int j = 0; j < len; j++)
      {
        if(i == j)
        {
          continue;
        }
        sum_start += stat[start[i]][start[j]];
        sum_link += stat[link[i]][link[j]];
      }
    }
    int tmp = abs(sum_start - sum_link);
    if(tmp < small || small == -1)
    {
      small = tmp;
    }
  } else 
  {
    if(number[0] == 0)
    {
      link.push_back(0);
      number.pop_front();
      ans(number, link, n);
    } else 
    {
      int len = number.size();
      for(int i = 0; i < len; i++)
      {
        link.push_back(number[0]);
        number.pop_front();
        ans(number, link, n);
        link.pop_back();
      }
    }
  }
}

/*
브루트 포스로 해결하는 방법을 생각해봤을땐 그렇게 어렵지 않았다.
근데 시간초과가 나와서 중복되는 경우가 많은 기존의 방식을 어떻게 개선하면 좋을지 고민해보았다. 
우리는 두 팀의 능력치 합의 차가 최소가 되도록 하는 경우를 구하고 싶다. 따라서 12 / 34 로 나누든, 34 / 12 로 나누든 구분할 필요가 없다.
따라서 오름차순으로 넣어준다는 기준을 세우고 스타트팀이 1을 무조건 포함한다는 조건을 넣고 풀자 훨씬 빠르게 풀 수 있었다.
무조건 1을 포함해야하는 이유는 어차피 중복되기때문에 1을 무조건 포함하는 경우만 구하면 나머지 반쪽을 구할 수 있기 때문이다.
ex) 1 2 3 4 일떄
1 2
1 3
1 4
만 구하면 나머지는 구할 필요가 없다. 중복되니깐.
*/

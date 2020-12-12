#include <cstdio>
#include <iostream>
using namespace std;

int ans[2][10000001] = {0};

int main()
{
  int n, m;
  int arr[100] ={0};
  int cost[100] = {0};
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &cost[i]);
  }

  for(int i = 0; i < 2; i++)
  {
    for(int j = 1; j <= m; j++)
    {
      ans[i][j] = 1000000000;
    }
  }

  for(int i = 0; i < n; i++)
  {
    int tmp_memory = arr[i];
    int tmp_cost = cost[i];
    for(int j = 1; j <= m; j++)
    {
      if(tmp_memory > j)
      {
        ans[1][j] = min(ans[0][0] + tmp_cost, ans[0][j]);  
      } else
      {
        ans[1][j] = min(ans[0][j - tmp_memory] + tmp_cost, ans[0][j]);
      }
    }
    for(int j = 1; j <= m; j++)
    {
      ans[0][j] = ans[1][j];
    }
  }
  printf("%d\n", ans[0][m]);
}

/*
대가리 깨지는 줄 알았네.
배낭문제랑 완전히 반대되는 경우라고 생각하면 됨. 
다양한 문제에 뚜까 맞으면서 성장해봅시다.
*/

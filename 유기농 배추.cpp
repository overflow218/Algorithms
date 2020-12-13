#include <iostream>
#include <cstdio>
using namespace std;

int n, m;

int arr[52][52] = {0}; // 1이면 배추, 0이면 없음
int checked[52][52] = {0}; // 1이면 이미 방문, 아니면 방문 아님. 

void clear(int n);
void search(int x, int y);

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
  int t, k, sum;
  scanf("%d", &t);
  for(int h = 0; h < t; h++)
  {
    sum = 0; // 개수 초기화
    scanf("%d %d %d", &n, &m, &k);
    int a, b;
    for(int i = 0; i < k; i++)
    {
      scanf("%d %d", &a, &b);
      arr[a + 1][b + 1] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
      for(int j= 1; j <= m; j++)
      {
        if(arr[i][j] == 1 && checked[i][j] == 0)
        {// 배추있고, 아직 방문 안했을때
          search(i, j);
          sum++;
        }
      }
    }
    printf("%d\n", sum);
    clear(n); // 썼던 배열 초기화
  }
  return 0;
}
void search(int x, int y)
{
  checked[x][y] = 1;
  int x1, y1;
  for(int i = 0; i < 4; i++)
  {
    x1 = x + dx[i];
    y1 = y + dy[i];
    if(arr[x1][y1] == 1 && checked[x1][y1] == 0)
    {
      search(x1, y1);
    }
  }
}
void clear(int n)
{
  for(int i = 1; i <= n; i++)
  {
    for(int j= 1; j <= n; j++)
    {
      arr[i][j] = 0;
      checked[i][j] = 0;
    }
  }
}

/*
dfs를 통해서 해결할 수 있습니다.
*/

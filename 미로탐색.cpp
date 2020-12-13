#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
int arr[102][102] = {0};
int checked[102][102] = {0};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void maze(int x, int y, int sum);

int ans = 20000;

int main()
{
  scanf("%d %d", &n, &m);
  char tmp[102];
  for(int i = 1; i <= n; i++)
  {
    scanf("%s", tmp);
    for(int j = 1; j <= m; j++)
    {
      arr[i][j] = tmp[j-1] - '0';
    }
  }
  maze(1, 1, 1);
  printf("%d\n", ans);
  return 0;
}

void maze(int x, int y, int sum)
{
  if(checked[x][y] != 0 && checked[x][y] <=sum) // 최적인 경우가 아니면 그냥 끝. 
  {
    return;
  }
  // sum < checked[x][y]  지금까지중에서 최적인 경우
  checked[x][y] = sum;

  if(x == n && y == m)
  { // 최종칸에 도착해서 최소값이 작다면 갱신해준다.
    if(sum < ans)
    {
      ans = sum;
    }
  }
  int x1, y1;
  for(int i = 0; i < 4; i++)
  {
    x1 = x + dx[i];
    y1 = y + dy[i];
    if(arr[x1][y1] == 1)
    {
      maze(x1, y1, sum + 1);
    }
  }
}

/*
기본 dfs를 조금 변형한 문제. 
단순히 주변에 묶여있는 개수를 구하는게 아니구, 
서로 접근해 있는 노드들끼리도 방문순서에 따라 답이 달라지기 때문에 
그부분을 잘 제어하는게 중요했던 문제.
*/

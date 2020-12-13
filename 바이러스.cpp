#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int graph[101][101] = {0};
int checked[1001] = {0};

void dfs(int idx);
void bfs(int idx);
int n;
int ans = 0;

int main()
{
  int m, a, b;
  scanf("%d %d", &n, &m);
  for(int i =0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  dfs(1);
  printf("%d\n", ans - 1);
  return 0;
}

void dfs(int idx)
{
  checked[idx] = 1;
  ans++;
  for(int i = 1; i <= n; i++)
  {
    if(graph[idx][i] == 1 && checked[i] == 0)
    {
      dfs(i);
    }
  }
}

void bfs(int idx)
{
  queue<int> q;
  q.push(idx);
  while(q.size() != 0)
  {
    int tmp = q.front();
    q.pop();
    if(checked[tmp]) // 하나의 정점이랑 연결된게 여러개일 수 있어서 이런 가능성도 있음. 
    {
      continue;
    }
    checked[tmp] = 1;
    for(int i = 1; i <= n; i++)
    {
      if(graph[tmp][i] == 1 && checked[i] == 0)
      {
        q.push(i);
      }
    }
  }
}

/*
간단한 dfs문제였습니다.
*/

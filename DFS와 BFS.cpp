#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int graph[1001][1001] = {0};
int checked[1001] = {0};

void dfs(int idx);
void bfs(int idx);
int n;

int main()
{
  int m, v;
  scanf("%d %d %d", &n, &m, &v);
  int a, b;
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  dfs(v);
  printf("\n");
  for(int i = 0; i <= n; i++)
  {
    checked[i] = 0;
  }
  bfs(v);
  return 0;
}

void dfs(int idx)
{
  checked[idx] = 1;
  printf("%d ", idx);
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
    printf("%d ", tmp);
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
기본적인 DFS와 BFS에 대한 문제입니다.
*/

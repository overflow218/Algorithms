#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int cost[16][16] = {0};
int path[16] = {0};
// path[i]는 i번 도시에서 출발도시로 갈때까지 드는 최소 비용을 나타냄. 
int ans = INT_MAX;
int n;
void tsp(int city, int sum, int * visited);

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      scanf("%d", &cost[i][j]);
    }
  }
  int visited[16] = {0};
  tsp(0, 0, visited); // 0번 도시를 시작도시로 정할거임.

  printf("%d\n", ans);
  return 0;
}

void tsp(int city, int sum, int * visited)
{
  if(visited[city]) // 이미 방문했던 도시인경우
  {
    if(city != 0) // 0번도시가 아닌경우 그냥 끝. 
    {
      return;
    }
    // 0번도시라도 아직 방문 안한 도시가 있다면 끝. 
    for(int i = 0; i < n; i++)
    {
      if(visited[i] == 0)
      {
        return;
      }
    }
    // 모든 도시를 방문하고 0번도시로 다시 돌아온 경우에만
    if(sum < ans)
    {
      ans = sum; // 기존 경로보다 작을경우 갱신해준다.
    }
    // 구한 최단 경로를 리턴한다.
  } else // 처음 방문하는 도시인경우. 
  {
    // 아직 city 도시부터 처음 도시까지 가는 최소비용이 안구해져 있는경우
    for(int i = 0; i < n; i++)
    {
      int tmp = cost[city][i];
      if(tmp != 0) // 방문할 수 있는도시에 대해서만,
      {
        visited[city] = 1;
        tsp(i, sum + tmp, visited);
        visited[city] = 0;
      }
    }
  }
}

/*
일단 첫번째 풀이로는 n = 16일때를 못 풀어. 
이게 n이 작을때는 쉽게 풀리는데 
시간복잡도가 O(n!)이라 이방법은 안돼
memoization을 쓰든 뭘하든 기록을 해놓고 사용할 필요가 있따. 

16
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 0 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 0 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 0 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 0 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 0 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 0 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 0 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 0 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 0 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 0 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 0 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 0 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 0 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 0 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0
*/

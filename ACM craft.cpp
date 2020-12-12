#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


int acm(int idx);
void clear();
// 전역 배열들 초기화 해주는 함수.
int cost[1001] = {0};
int ans[1001] = {0};
int order[1001][1001] = {0};

int main()
{
  int t, n, k, w, to, from;
  scanf("%d", &t);
  for(int h = 0; h < t; h++)
  {
    clear();
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
      scanf("%d", &cost[i]);
    }
    for(int i = 0; i < k; i++)
    {
      scanf("%d %d", &to, &from);
      int idx = ++order[from][0];
      order[from][idx] = to;
    }
    scanf("%d", &w);
    printf("%d\n", acm(w));
  }
}

int acm(int idx)
{
  int len = order[idx][0]; // idx번 건물을 짓기위해 먼저 지어야하는 건물의 수
  if(ans[idx] != -1) // 이미 건물 짓는데 걸리는 시간 아는 경우
  {
    return ans[idx];
  } else if(len == 0) // 따로 지을 건물이 필요 없는경우.  
  {
    ans[idx] = cost[idx];
    return ans[idx];
  } else // 선행 건물을 지어야하는 경우
  {
    int tmp = 0;
    for(int i = 1; i <= len; i++)
    {
      tmp = max(tmp, acm(order[idx][i]));
      // 선행건물들 중에서 제일 시간 오래 걸리는 놈이 정답이 되어야 함.
    }
    ans[idx] = tmp + cost[idx]; // 선행건물 짓는데 걸리는 시간 + idx건물 짓는데 걸리는 시간
    return ans[idx];
  }
}

void clear()
{
  for(int i = 0; i <= 1000; i++)
  {
    for(int j =0; j<= 1000; j++)
    {
      order[i][j] = 0;
    }
    ans[i] = -1;
    cost[i] = 0;
  }
}

/*
분명 프로그램은 야무지게 잘 짠거 같은데 자꾸 61% 정도에서 시간초과에 걸려서 
생각을 해보았따. 이게 이미 구한건지 아닌지를 ans[idx]의 값이 0 인지 아닌지를 기준으로 판단했는데, 
문제 조건에서 빌딩을 짓는데 걸리는 시간이 0일수도 있어서 이럴경우 계속 무한루프를 돌게된다. 
따라서 처음 ans배열을 초기화할때 -1로 초기화해주면 이런 문제를 해결할 수 있다. 

느낀점 
1. 전역 배열 선언할때, 초기값을 막 넣어주지말구 생각하고 넣어주기.
2. new 로 할당받고 delete로 지워도 메모리는 회수되지만 그자리에 값은 그대로 남아있어서 문제가 발생하는 경우가 많다. 
테스트케이스가 여러개로 같은 배열을 여러번 사용해야 하는 경우에는 
1. new로 할당받을때마다 계속 초기화 해준다. 
2. 그냥 전역변수 선언해놓고, 초기화 해준다. 
사실상 2번 방법이 훨씬 편하다고 볼 수 있다. 

*/

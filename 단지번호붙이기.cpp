#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int apart[27][27] = {0};
int checked[27][27] = {0};
/*
+++++
+---+
+---+
+---+
+++++ 이런 느낌으로 만들려고 27 27 쓴거임. 
*/
int n;
int numApart = 0;
int tsum = 0;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans[1000] = {0};

void search(int x, int y, int idx);
int main()
{ 
  scanf("%d", &n);
  char tmp[30];
  for(int i = 1; i <= n; i++)
  {
    scanf("%s", tmp);
    for(int j = 1; j <= n; j++)
    {
      apart[i][j] = tmp[j-1] - '0';
    }
  }

  for(int i = 1; i <= n; i++)
  {
    for(int j= 1; j <= n; j++)
    {
      if(apart[i][j] == 1 && checked[i][j] == 0) // 아파트가 있고 아직 방문 안한 경우에만 들어간다.
      {
        numApart++;
        tsum = 0;
        search(i, j, numApart - 1);
      }
    }
  }
  sort(ans, ans + numApart);
  printf("%d\n", numApart);
  for(int i = 0; i < numApart; i++)
  {
    printf("%d\n", ans[i]);
  }
  
  return 0;
}


void search(int x, int y, int idx)
{
  if(checked[x][y] == 1) // 이미 온거니깐 나가기. 
  {
    return;
  } else 
  {
    tsum++;
    checked[x][y] = 1;
    int x1, y1;
    for(int i = 0; i < 4; i++)
    {
      x1 = x + dx[i];
      y1 = y + dy[i];
      if((1 <= x1 && x1 <= n) && (1 <= y1 && y1 <= n))
      {
        if(apart[x1][y1] == 1 && checked[x1][y1] == 0)
        {
          search(x1, y1, idx);
        }
      }
    }
    ans[idx] = tsum;
  }
}


/*
dfs를 이용해 푸는 문제였습니다.
*/

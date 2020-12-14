#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;

int arr[1002][1002] = {0};
int checked[1002][1002] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int ans = 0;
int nothing = 0; // -1 칸의 갯수를 말함.


deque<int> tmpx;
deque<int> tmpy;
deque<int>x;
deque<int>y;

void tomato(deque<int>& x, deque<int>&y, int day);
bool isDone();

int main()
{
  int tmp;
  scanf("%d %d", &m, &n);
  for(int i = 1; i <= n; i++)
  {
    for(int j= 1; j <= m; j++)
    {
      scanf("%d", &tmp);
      arr[i][j] = tmp;
      if(tmp == 1)
      {
        x.push_back(i);
        y.push_back(j);
        checked[i][j] = 1;
      } else if(tmp == -1) // 토마토 없는거니깐 미리 checked바꿔 놓아야함. 
      {
        checked[i][j] = 1;
        nothing++;        
      }
    }
  }

  for(int i = 0; i <= m + 1; i++)
  {
    checked[0][i] = 1;
    checked[n + 1][i] = 1;
  }
  for(int i = 0; i <= n + 1; i++)
  {
    checked[i][0] = 1;
    checked[i][m+1] = 1;
  }

  if(x.size() + nothing == n * m)
  {
    printf("0\n");
    return 0;
    // 처음부터 다 익어 있던 경우
  }
  tomato(x, y, 0);
  if(ans == 0)
  {
    printf("-1\n");
  } else 
  {
    printf("%d\n", ans);
  }
  return 0;
}

void tomato(deque<int>& x, deque<int>& y, int day)
{
  tmpx.clear();
  tmpy.clear();
  int tmp, tx, ty, x1, y1;
  if(isDone())
  {
    if(day > ans)
    {
      ans = day;
    }
    return;
  }

  int len = x.size();
  for(int i = 0; i < len; i++)
  {
    tx  = x[i];
    ty = y[i];
    //checked[tx][ty] = 1;
    for(int j= 0; j < 4; j++)
    {
      x1 = tx + dx[j];
      y1 = ty + dy[j];
      if(arr[x1][y1] == 0 && checked[x1][y1] == 0)
      { // 안익은 토마토이면서, 아직 방문 안한경우. 
        tmpx.push_back(x1);
        tmpy.push_back(y1);
        checked[x1][y1] = 1;
      }
      // 중복해서 들어가는걸 막아줘야해
    }
  }
  // 불가능한 경우에 무한루프 도는걸 막아주어야해
  if(tmpx.size() == 0)
  {
    return;
  }
  x = tmpx;
  y = tmpy;
  tomato(x, y, day + 1);
}

bool isDone()
{
  for(int i = 1; i <= n; i++)
  {
    for(int j= 1; j <= m; j++)
    {
      if(checked[i][j] == 0)
      {
        return false;
      }
    }
  }
  return true;
}

/*
풀었다고 생각했는데, 메모리 초과가 나와서 당황했던 문제...
참조자 & 를 사용해서 메모리초과를 해결할 수 있었따. 
근데 문제 제한조건이 256MB였는데, 전역배열 선언한게 4MB밖에 안되고
그런데 왜 문제가 생겼던걸까?
*/

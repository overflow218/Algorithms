#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;

int arr[100][100][100] = {0};
int checked[100][100][100] = {0};
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int n, m, h;
int ans = 0;
int nothing = 0; // -1 칸의 갯수를 말함.

deque<int> x;
deque<int> y;
deque<int> z;

void tomato(deque<int>& x, deque<int>&y, deque<int> &z, int day);
bool isDone();

int main()
{
  int tmp;
  scanf("%d %d %d", &m, &n, &h);

  for(int k = 0; k < h; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        scanf("%d", &tmp);
        arr[i][j][k] = tmp;
        if(tmp == 1)
        {
          x.push_back(i);
          y.push_back(j);
          z.push_back(k);
          checked[i][j][k] = 1;
        } else if(tmp == -1)
        {
          checked[i][j][k] = 1;
          nothing++;
        }
      }
    }
  }

  if(x.size() + nothing == n * m * h)
  {
    printf("0\n");
    return 0;
    // 처음부터 다 익어 있던 경우
  }
  tomato(x, y, z, 0);
  if(ans == 0)
  {
    printf("-1\n");
  } else 
  {
    printf("%d\n", ans);
  }
  return 0;
}

void tomato(deque<int>& x, deque<int>& y, deque<int> &z, int day)
{
  int tmp, tx, ty, tz, x1, y1, z1;
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
    tx  = x[0];
    ty = y[0];
    tz = z[0];
    x.pop_front();
    y.pop_front();
    z.pop_front();
    for(int j = 0; j < 6; j++)
    {
      x1 = tx + dx[j];
      y1 = ty + dy[j];
      z1 = tz + dz[j];
      if(((0 <= x1 && x1 < n) && (0 <= y1 && y1 < m)) && (0 <= z1 && z1 < h))
      {
        if(arr[x1][y1][z1] == 0 && checked[x1][y1][z1] == 0)
        { // 안익은 토마토이면서, 아직 방문 안한경우. 
          x.push_back(x1);
          y.push_back(y1);
          z.push_back(z1);
          checked[x1][y1][z1] = 1;
        }
      }
      // 중복해서 들어가는걸 막아줘야해
    }
  }
  // 불가능한 경우에 무한루프 도는걸 막아주어야해
  // 아무것도 안들어간 상태로 계속 다음걸로 넘어간단말이야.
  if(x.size() == 0)
  {
    return;
  }
  tomato(x, y, z, day + 1);
}

bool isDone()
{

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      for(int k = 0; k < h; k++)
      {
        if(checked[i][j][k] == 0)
        {
          return false;
        }
      }
    }
  }
  return true;
}

/*
이전에 풀었던 토마토 문제의 3차원 업그레이드 버전이다.
총 3번만에 풀었다.
1번째 도전 -> i,j, k 등 변수이름을 많이 쓰다보니 변수이름을 헷갈려서 오타를 내서 틀렸다.
2번째 도전 -> 시간초과가 났다. 알고보니 편의상 덱을 복사해서 쓰던부분에서 시간을 많이 잡아먹었던거였다. 
3번째 도전 -> 1, 2의 문제를 해결하니 풀렸당.

언제나 조심할것
1. 변수이름은 확실하게 짓자. for문에서 쓰이는 변수도 i, j, k등 순서를 정해놓고 쓰자. 
2. 불필요한 동작을 안해도 된다면 안하고 풀자. 크기가 작을때는 아무 문제 없어도 인풋값의 크기가 커지면 문제가 되는 경우가 많다.
*/

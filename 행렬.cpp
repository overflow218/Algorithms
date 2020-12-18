#include <cstdio>
#include <cstring>
int a[50][50] = {0};
int b[50][50] = {0};

void isSame();
void getInput();
void change(int i, int j);

int n, m;
int count = 0;

int main()
{
  scanf("%d %d", &n, &m);
  getInput();

  for(int i = 0; i < n - 2; i++)
  {
    for(int j = 0; j < m - 2; j++)
    {
      if(a[i][j] != b[i][j])
      { // 다를때만 바꿔줘야 하는데 이 조건을 빼먹었네 ㄷㄷ..
        change(i, j);
        count++;
      }
    }
    if(a[i][m-2] != b[i][m-2] || a[i][m-1] != b[i][m-1])
    {
      printf("-1");
      return 0;
    }
  }
  isSame();
  return 0;
}

void isSame()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(a[i][j] != b[i][j])
      {
        printf("-1");
        return;
      }
    }
  }
  printf("%d", count);
}

void getInput()
{
  char tmp[100];
  for(int i = 0; i < n; i++)
  {
    scanf("%s", tmp);
    int len = strlen(tmp);
    for(int j = 0; j < len; j++)
    {
      a[i][j] = tmp[j] -'0';
    }
  }

  for(int i = 0; i < n; i++)
  {
    scanf("%s", tmp);
    int len = strlen(tmp);
    for(int j = 0; j < len; j++)
    {
      b[i][j] = tmp[j] -'0';
    }
  }
}

void change(int i, int j)
{
  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 3; y++)
    {
      a[i+x][j+y] = (a[i+x][j+y] + 1) % 2;
    }
  }
}

/*
바꿀때 a[i][j] != b[i][j]일때만 바꿔야 하는데
이 조건을 빼먹어서 틀렸었음. 이런 디테일에 신경쓰자. 
*/

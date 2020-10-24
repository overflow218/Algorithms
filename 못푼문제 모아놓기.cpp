// 백준 2573번 빙산문제.
#include <cstdio>

int arr[300][300] = {0};
int ans[300][300] = {0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

bool isDividedTwo();
bool isEmpty();
void oneYearPass();
int main()
{

  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
  int count = 0;
  while(!isEmpty())
  {
    oneYearPass();
    count++;
    if(isDividedTwo())
    {
      printf("%d", count);
      return 0;
    }
    printf("-----------------------\n");
    for(int i = 0; i < n; i++)
    {
      for(int j= 0; j < m; j++)
      {
        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }
  }
  printf("0");
  return 0;
}

void oneYearPass()
{
  for(int i = 1; i < n - 1; i++)
  {
    for(int j = 1; j < m - 1; j++)
    {
      int tmp = 0;
      if(arr[i][j] == 0)
      {
        continue;
      }
      for(int k = 0; k < 4; k++)
      {
        if(arr[i + dx[k]][j + dy[k]] == 0)
        {
          tmp++;
        }
      }
      int x = arr[i][j] - tmp;
      ans[i][j] = x > 0 ? x : 0;
    }
  }

  for(int i = 1; i < n - 1; i++)
  {
    for(int j = 1; j < m - 1; j++)
    {
      arr[i][j] = ans[i][j];
    }
  }
}

bool isEmpty()
{
  for(int i = 1; i < n - 1; i++)
  {
    for(int j= 1; j < m - 1; j++)
    {
      if(arr[i][j] != 0)
      {
        return false;
      }
    }
  }
  return true;
}


bool isDividedTwo()
{
  int sum = 0; // 떨어져있는 조각을 세는거얌. 
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(arr[i][j] == 0)
      {
        continue;
      }
      // 여기 루프 들어간다는건 arr[i][j] != 0 이라는 거지. 
      int flag = 0;
      for(int k = 0; k < 4; k++)
      {
        if(arr[i + dx[k]][j + dy[k]] != 0)
        {
          flag++;
        }
      }
      if(flag == 0) // 혼자 떨어져 나온 조각이란 말이니까. 
      {
        sum++;
        if(sum == 2)
        {
          return true;
        }
      }
    }
  }
  return false;
}

/*
지금 두조각으로 나눠졌는지 확인하는게 틀렸는데, 
하나 하나 조각난거는 판별하는데, 이렇게 덩어리로 나온걸 판별못하고 있어. 
0 0 0 0 0 
0 5 0 5 0 
0 8 0 8 0 
0 5 0 5 0 
0 0 0 0 0 

그래프 같은거 공부가 부족하다... 분발하자... 

*/

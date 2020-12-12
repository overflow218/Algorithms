#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int arr[1000][1000] ={0};
int ans[1000][1000] = {0};
int big = 0;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
// 아 이거 공간 안띄워놓고 스트링으로 들어와서 이런거네 쒸볼

  char tmp[1001];
  for(int i = 0; i < n; i++)
  {
    scanf("%s", tmp);
    for(int j = 0; j < m; j++)
    {
      arr[i][j] = tmp[j] - '0';
    }
  }

  for(int i = 0; i < n; i++)
  {
    if(arr[i][0] == 0)
    {
      ans[i][0] = -1;
    } else 
    {
      ans[i][0] = 1;
    }
  }

  for(int i = 0; i < m; i++)
  {
    if(arr[0][i] == 0)
    {
      ans[0][i] = -1;
    } else 
    {
      ans[0][i] = 1;
    }
  }

  for(int i = 1; i < n; i++)
  {
    for(int j = 1; j < m; j++)
    {
      if(arr[i][j] == 0) // 일단 i,j가 0이면 아무 의미 없음. 
      {
        ans[i][j] = -1;

      } else if(ans[i-1][j-1] == -1 || (ans[i][j-1] == -1 || ans[i-1][j] == -1))
      {
        ans[i][j] = 1;
      } else // 주의의 3블록 모두 1이상인 경우
      {
        ans[i][j] = min(ans[i-1][j-1], min(ans[i-1][j], ans[i][j-1])) + 1;
      }
    }
  }
  for(int i = 0; i < n; i++)
  { // 코드 더럽게 중간에 최댓값 찾는부분 넣기 싫어서 그냥 이렇게 풀었음. 
    for(int j= 0; j < m; j++)
    {
      if(ans[i][j] > big)
      {
        big = ans[i][j];
      }
    }
  }
  printf("%d\n", big * big);
  return 0;
}

/*
전에 못풀었던 문젠데 
다시 보니깐 잘 풀렸넹. 
DP 딱 대라 
*/

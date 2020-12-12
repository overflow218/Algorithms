#include <cstdio>
#include <iostream>
using namespace std;

int garo[17][17] = {0}; // i,j 에 도착했을때 가로인 경우의 수
int sero[17][17] = {0}; // ㅑ
int diag[17][17] = {0}; // 대각선으로 가는 방법의 수
int n;

int arr[17][17] = {0};
int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }


  garo[1][2] = 1;
  // 1줄에는 가로만 놓일 수 있음. 
  for(int i = 3; i <= n; i++)
  {
    if(arr[1][i] == 0) // 빈칸일때
    {
      garo[1][i] = garo[1][i-1];
    }
  }
  
  for(int i = 2; i <= n; i++)
  {
    for(int j= 1; j <= n; j++)
    {
      if(arr[i][j] == 0)// 일단 빈칸일때만 가능하지요. 
      {
        garo[i][j] =  garo[i][j-1] + diag[i][j-1];
        sero[i][j] = sero[i-1][j] + diag[i-1][j];
        if(arr[i][j-1] == 0 && arr[i-1][j] == 0)
        {
          diag[i][j] = diag[i-1][j-1] + garo[i-1][j-1] + sero[i-1][j-1];
        }
      }
    }
  }
  int ans = garo[n][n] + sero[n][n] + diag[n][n];
  printf("%d\n", ans);
  return 0;
}

/*
어려워 보였지만 나눠서 생각해보면 풀 수 있습니다.ㅇ
쫄지 맙시다. 다이나믹 프로그래밍 딱대라 딱대
*/

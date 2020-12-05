#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int board[14][14] = {0};
// 체스판을 나타냄. 퀸 안놓여있으면 0, 놓여있으면 1이다.
int ans; 
// 정답 경우의 수를 나타냄. 3백만 언저리가 맥스답이라 int로 선언함.
int queen[14] = {0}; // 퀸을 놓은 idx들을 저장해놓을 배열임. 
int row[14] = {0}; // board[x][y]에서 퀸이 놓인 y값을 담고 있음. 


bool isPossible(int column, int row, int n, int count);
// board[column][row] 자리에 퀸을 놓는게 가능한지 아닌지 판단해주는 함수. 

bool isPossible(int column, int row, int n, int count)
{
  for(int i = 0; i < count; i++)
  {
    int x2 = queen[i] / n;
    int y2 = queen[i] % n;
    int diffx = column - x2;
    int diffy = row - y2;
    if(diffx == diffy || diffx + diffy == 0)
    {
      return false;
    }
  }
  return true;
}


void Queen(int column, int n, int count);
// column은 현재의 칼럼을,  n은 주어진 n을, count는 놓은 퀸 개수를 나타냄

int main()
{
  int n;
  scanf("%d", &n);
  Queen(0, n, 0);
  printf("%d\n", ans);
  return 0;
} 

void Queen(int column, int n, int count)
{
  if(count == n) // 퀸을 다 놓은 경우
  {
    ans++;
    return;
  } else if(column == n) // 이건 안되는 경우지.
  {
    return; 
  }
  for(int i = 0; i < n; i++)
  {
    if(row[i]) // 이미 퀸을 놓은 row라면 넘어가기
    {
      continue;
    }
    if(isPossible(column, i, n, count))
    {
      queen[count] = column * n + i;
      row[i] = 1;
      Queen(column + 1, n, count + 1);
      queen[count] = 0;
      row[i] = 0;
    }
  }
  /*
  이번 column에서 가능한 row가 없어서 퀸을 못 놨다면 절대로 n개를 놓을
  가망이 없으니깐 그냥 종료하면 안됨. 
  */
}

/*
이번 백트래킹 문제에 대한 고찰. 
우선 백트래킹하면 N-queen 일 정도로 대표적인 문제라고 함. 
일단 접근은 잘했어. 근데 시간안에 못푸는게 문제지. 
그 알고리즘 책 보면서 늘은 부분은 시간은 어찌됐든, 논리적으로 
무조건 풀 수 있는 방법을 찾았다는게 중요한거 같아. 
그게 문제풀이의 첫걸음이거든. 왜냐면 브루트 포스로 풀 수 있다면
그걸 좀 더 효율적으로 바꾸면 되는거니까. 
근데 이번 문제에서는 시간초과가 나오는 거 때문에 n = 14 일 때를 
해결하지 못했어. 나는 단순히 모든 경우의 수를 다 구하려고 했기때문에 
경우의 수가 너무 켜져버렸거든. 
근데 이렇게 생각해보자. 퀸은 가로 세로 대각선을 다 이동할 수 있으니깐, 
무조건 하나의 열과 행에는 하나의 퀸만이 들어갈 수 있다. 마치 스도쿠에서 가로 세로에 같은 수가 들어갈 수 없는 거랑 비슷하게 말이야. 
그래서 맨 윗줄에서부터 아랫줄로 내려가면서 
그줄에서 놓을 수 있는 부분을 찾아서 놓을 수 있으면 놓고
놓을 수 있는 경우가 하나도 없다면 n개를 놓는 것은 불가능한 경우이므로
빨리 종료하도록 하여 문제를 해결하였다. 
사용한 방법은 똑같지만 좀 더 생각하여 탐색의 범위를 크게 줄였던것이 시간안에 풀 수 있도록 한 발전이라고 생각한다. 
*/

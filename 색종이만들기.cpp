#include <cstdio>
#include <iostream>
using namespace std;

int white = 0;
int blue = 0;
// 흰 색종이 수와 파란 색종이 수를 나타낸다.

bool isSameColor(int ** board, int x, int y, int width);
void colorPaper(int ** board, int x, int y, int width);


int main()
{
  int n;
  scanf("%d", &n);
  int ** board = new int*[n];
  for(int i = 0; i < n; i++)
  {
    board[i] = new int[n];
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      scanf("%d", &board[i][j]);
    }
  }
  colorPaper(board, 0, 0, n);
  printf("%d\n%d\n", white, blue);
}

bool isSameColor(int ** board, int x, int y, int width)
{
  int tmp = board[x][y];
  int boundX = x + width;
  int boundY = y + width;
  for(int i = x; i < boundX; i++)
  {
    for(int j = y; j < boundY; j++)
    {
      if(board[i][j] != tmp)
      {
        return false;
      }
    }
  }
  return true;
}

// (x, y)가 왼쪽 상단 모서리인 정사각형이 같은 색으로 이루어졌는지 
// 아닌지 판단하는 함수. 
// 더이상 쪼갤 수 없거나, 같은 색깔일때 true를 리턴
// 그 외의 경우에는 false를 리턴

void colorPaper(int ** board, int x, int y, int width)
{
  if(width == 1 ||isSameColor(board, x, y, width)) // Basecase
  {
    if(board[x][y]== 1)
    {
      blue++;
    } else
    {
      white++;
    }
  } else
  {
    int tmpWidth = width / 2;
    colorPaper(board, x, y, tmpWidth);
    colorPaper(board, x + tmpWidth, y, tmpWidth);
    colorPaper(board, x, y + tmpWidth, tmpWidth);
    colorPaper(board, x + tmpWidth, y + tmpWidth, tmpWidth);
  }
}

/*
분할정복을 이용하는 어렵지 않은 문제였습니다.
*/

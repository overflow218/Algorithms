#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool isSameColor(int ** board, int x, int y, int width);
void colorPaper(int ** board, int x, int y, int width);

int negative = 0;
int zero = 0;
int positive = 0;

int main()
{
  int n;
  scanf("%d", &n);
  int ** board = new int* [n];
  for(int i = 0; i < n; i++)
  {
    board[i] = new int[n];
    for(int j = 0; j < n; j++)
    {
      scanf("%d", &board[i][j]);
    }
  }

  colorPaper(board, 0, 0, n);

  for(int i = 0; i < n; i++)
  {
    delete board[i];
  }
  delete [] board;

  printf("%d\n%d\n%d\n", negative, zero, positive);
  return 0;
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
  if(isSameColor(board, x, y, width)) // Basecase
  {
    int tmp = board[x][y];
    if(tmp < 0)
    {
      negative++;
    } else if(tmp == 0)
    {
      zero++;
    } else
    {
      positive++;
    }
  } else
  { 
    int nextWidth = width / 3;
    colorPaper(board, x, y, nextWidth);
    colorPaper(board, x, y + nextWidth, nextWidth);
    colorPaper(board, x, y + nextWidth * 2, nextWidth);
    colorPaper(board, x + nextWidth, y, nextWidth);
    colorPaper(board, x + nextWidth, y + nextWidth, nextWidth);
    colorPaper(board, x + nextWidth, y + nextWidth * 2, nextWidth);
    colorPaper(board, x + nextWidth * 2, y, nextWidth);
    colorPaper(board, x + nextWidth * 2, y + nextWidth, nextWidth);
    colorPaper(board, x + nextWidth * 2, y + nextWidth * 2, nextWidth);
  }
}

/*
이전 문제들이랑 비슷해서 어렵지 않게 풀었음. 
*/

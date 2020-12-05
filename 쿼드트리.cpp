#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool isSameColor(char ** board, int x, int y, int width);
void colorPaper(char ** board, int x, int y, int width);

int main()
{
  int n;
  scanf("%d", &n);
  char ** board = new char*[n];
  for(int i = 0; i < n; i++)
  {
    board[i] = new char[n];
    scanf("%s", board[i]);
  }
  colorPaper(board, 0, 0, n);
  return 0;
}

bool isSameColor(char ** board, int x, int y, int width)
{
  char tmp = board[x][y];
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

void colorPaper(char ** board, int x, int y, int width)
{
  if(isSameColor(board, x, y, width)) // Basecase
  {
    printf("%c", board[x][y]);
  } else
  { 
    int tmpWidth = width / 2;
    printf("(");
    colorPaper(board, x, y, tmpWidth); // 왼쪽위
    colorPaper(board, x, y + tmpWidth, tmpWidth);// 오른쪽 위
    colorPaper(board, x + tmpWidth, y, tmpWidth); // 왼쪽 아래
    colorPaper(board, x + tmpWidth, y + tmpWidth, tmpWidth); // 오른쪽 아래
    printf(")");
  }
}

/*
문제자체는 어렵지 않게 풀었는데 입력이 
11111000 처럼 붙어서 들어오는데 %d 랑 %c로 받으려고 하다가 
삽질 30분정도 한듯. 이렇게 한줄로 딱 붙어서 오는 경우에는 
%s로 해서 char * 로 받은다음에 나눠서 해결해준게 훨씬 좋은 방법임.
*/

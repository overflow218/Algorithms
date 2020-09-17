#include <iostream>
using namespace std;

char block[20][20]; // #은 검은칸,  . 은 흰칸을 나타냄.

int dx1[4] = {0, 1, 1, 0};
int dy1[4] = {1, -1, 0, 1};
int dx2[4] = {1, 1, 1, 1};
int dy2[4] = {0, 0, 1, 1};
// x,y 를 L자 블록의 가운데 블록이라 할때, 가능한 4가지 경우에 대한 x,y 좌표를 나타냄. 

void reset(); // block을 초기화하는 함수

bool isValid(int x1, int y1, int x2, int y2, int h, int w);
// 구체적인 L자 블록에 대해서 범위안에 있는지, 흰칸인지 판단. 
// 유효하면 true 리턴, 아니면 false 리턴

int coverTowhite(int leftBlock, int x, int y, int h, int w);
// 흰칸을 덮을수 있는 경우의 수를 구하는 함수 
// leftBlock 은 남은 흰색 블록의 수를 나타냄. 
// x, y 는 현재 위치를 나타냄. h와 w는 주어진 블록의 세로, 가로를 나타냄. 

int main()
{
  int c; // 전체 테스트 케이스 수
  int h, w; // 각각 블록의 세로와 가로를 나타냄
  char ch; // # 과 .을 받아들여 흰칸과 검은칸을 구분해줄 임시변수
  cin >> c;
  for(int i = 0; i < c; i++)
  {
    cin >> h >> w;
    int whiteblock = 0; // 흰칸의 수를 저장하는 변수
    for(int x = 0; x < h; x++)
    {
      for(int y = 0; y < w; y++)
      {
        cin >> ch;
        block[x][y] = ch;
        if(ch == '.')
        {
          whiteblock++;
        }
      }
    }

    if(whiteblock % 3 != 0) // 3의 배수가 아니라면 L자 블록으로 덮을 수 없음.
    {
      cout << 0 << '\n';
      reset();
    } else 
    {
      int ans = coverTowhite(whiteblock, 0, 0, h, w);
      cout << ans << '\n';
      reset();
    }
  }
  return 0;
}

int coverTowhite(int leftBlock, int x, int y, int h, int w)
{
  if(leftBlock == 0) // basecase 더이상 바꿀 블록이 없는거니까 1 리턴
  {
    return 1;
  } else if(x >= h || y >= w) // 주어진 칸을 벗어나는거니깐 0 리턴
  {
    return 0;
  } else if(block[x][y] != '.') // x,y가 흰칸이 아닌경우
  {
    if(y < w - 1)
    {
      return coverTowhite(leftBlock, x, y + 1, h, w);
    } else 
    {
      return coverTowhite(leftBlock, x + 1, 0, h, w);
    }
  }

  int ans = 0;
  int flag = 0; 

  int tx1, tx2, ty1, ty2; // 각각 L자 블록의 나머지 2개의 칸을 나타냄.
  for(int i = 0; i < 4; i++)
  {
    tx1 = x + dx1[i];
    tx2 = x + dx2[i];
    ty1 = y + dy1[i];
    ty2 = y + dy2[i];
    if(isValid(tx1, ty1, tx2, ty2, h, w))
    {
      flag = 1;
      block[x][y] = '#';
      block[tx1][ty1] = '#';
      block[tx2][ty2] = '#';
      if(y < w - 1)
      {
        ans += coverTowhite(leftBlock - 3, x, y + 1, h, w);
      } else 
      {
        ans += coverTowhite(leftBlock - 3, x + 1, 0, h, w);
      }
      block[x][y] = '.';
      block[tx1][ty1] = '.';
      block[tx2][ty2] = '.';
    }
  }
  // 유효한 L자 블록이 있는 경우라도 안놓고 넘어가보는 경우가 필요해. 
  if(flag == 0)
  {
    if(y < w - 1)
    {
      return coverTowhite(leftBlock, x, y + 1, h, w);
    } else 
    {
      return coverTowhite(leftBlock, x + 1, 0, h, w);
    }
  }
  return ans;
}


bool isValid(int x1, int y1, int x2, int y2, int h, int w)
{
  if(0 <= x1 && x1 <= h - 1){
    if(0 <= x2 && x2 <= h - 1)
    {
      if(0 <= y1 && y1 <= w - 1)
      {
        if(0 <= y2 && y2 <= w - 1)
        {
          if(block[x1][y1] == '.' && block[x2][y2] == '.')
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}

void reset()
{
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 20; j++)
    {
      block[i][j] = '.';
    }
  }
}

//예제
// 3
// 3 7
// #.....#
// #.....#
// ##...##
// 3 7 
// #.....#
// #.....#
// ##..###
// 8 10
// ##########
// #........#
// #........#
// #........#
// #........#
// #........#
// #........#
// ##########
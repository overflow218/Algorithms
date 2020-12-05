#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int arr[9][9]= {0};
bool clear = false; // 문제 풀면 true로 바꿀거얌. 
void sdoku(int idx);
// 스도쿠를 놓아주는 함수 ㅋㅋ
deque <int> availableNumber(int x, int y);
// x,y 자리에 대해 놓을 수 있는 수를 구해주는 함수. 

int main()
{
  for(int i = 0; i < 9; i++)
  {
    for(int j = 0; j < 9; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
  sdoku(0);
  return 0;
}

void sdoku(int idx)
{
  if(clear)
  {
    return;
  }else if(idx == 81)
  {
    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
      {
        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }
    clear = true;
  } else
  {
    int x = idx / 9;
    int y = idx % 9;

    if(arr[x][y]) // 이미 채워져 있는 경우
    {
      sdoku(idx + 1);
    } else // 채워야하는 경우. 
    {
      deque <int> avail = availableNumber(x, y); // 유효한 수의 집합. 
      int len = avail.size();
      if(len == 0)
      {
        return; // 불가능한 경우니까 그냥 끝내
      }
      for(int i = 0; i < len; i++)
      {
        arr[x][y] = avail[i];
        sdoku(idx + 1);
        arr[x][y] = 0; // 이 줄을 쓰면 맞고 안쓰면 틀리는데 왜 그럴까?? 상관없지 않나싶은데..
      }
    }
  }
}

deque <int> availableNumber(int x, int y)
{
  int blockX = x / 3 * 3;
  int blockY = y / 3 * 3;
  // blockX, blockY 는 3 * 3 블록의 왼쪽 상단 모서리를 가르킴.
  deque <int> ans;
  int tmp[10] = {0};
  for(int i = 0; i < 9; i++)
  {
    if(arr[x][i])
    {
      tmp[arr[x][i]]++;
    }
  }
  for(int i = 0; i < 9; i++)
  {
    if(arr[i][y])
    {
      tmp[arr[i][y]]++;
    }
  }
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(arr[blockX + i][blockY + j])
      {
        tmp[arr[blockX + i][blockY + j]]++;
      }
    }
  }
  for(int i = 1; i <= 9; i++)
  {
    if(tmp[i] == 0) // 0이란건 아직 안나왔따는 소리임. 
    {
      ans.push_back(i);
    }
  }
  return ans;
}

/*
주석으로 코멘트 달아놓은 부분을 잘 이해를 못하겠음.
내생각엔 아무 차이 없는거 같은데 이런 차이를 만들어 내다니 ㅋㅋ..
*/

#include <iostream>
using namespace std;

int SWITCH[10][6] = {{3, 0, 1, 2}, {4, 3, 7, 9, 11}, {4, 4, 10, 14, 15}, {5, 0, 4, 5, 6, 7}, {5, 6, 7, 8, 10, 12}, {4, 0, 2, 14, 15}, {3, 3, 14, 15}, {5, 4, 5, 7, 14, 15}, {5, 1, 2, 3, 4, 5}, {5, 3, 4, 5, 9, 13}};
// 미리 주어진 스위치 Switch[i][0] 은 i스위치와 연결된 시계의 개수를 의미함.
int Clock[16]; // 시계

bool isDone();
// 시계가 모두 12시로 정렬되었다면 true, 아니면 false 리턴.

int controlWatch(int idx, int cont, int count);
/*
idx는 현재 볼 스위치의 번호, cont는 idx스위치를 연속해서 몇번 눌렀는지를 표시하는 변수
 count는 현재까지 누른 스위치의 수.
*/

void pushOrPushBack(int type, int idx);
// type 이 1이면 idx번 스위치를 누르고, -1 이면 되돌리기

void pr()
{
  for(int i = 0; i < 16; i++)
  {
    cout << Clock[i] << ' ';
  }
  cout <<'\n';
}

int main()
{
  int c; // 테스트 케이스의 개수
  int tmp; // 임시로 인풋을 담을 변수
  cin >> c;
  for(int i = 0; i < c; i++)
  {
    for(int j = 0; j < 16; j++)
    {
      cin >> tmp;
      Clock[j] = tmp % 4; 
    }
    int ans = controlWatch(0, 0, 0);
    cout << ans;
  }
  return 0;
}

bool isDone()
{
  for(int i = 0; i < 16; i++)
  {
    if(Clock[i] != 0)
    {
      return false;
    }
  }
  return true;
}

void pushOrPushBack(int type, int idx)
{
  if (type == 1)// 누르기
  {
    for(int i = 1; i <= SWITCH[idx][0]; i++)
    {
      int tmp = Clock[SWITCH[idx][i]];
      if(tmp == 0)
      {
        Clock[SWITCH[idx][i]] = 3;
      }else 
      {
        Clock[SWITCH[idx][i]]--;
      }
    }
  } else // 되돌리기
  {
    for(int i = 1; i <= SWITCH[idx][0]; i++)
    {
      int tmp = Clock[SWITCH[idx][i]];
      if(tmp == 3)
      {
        Clock[SWITCH[idx][i]] = 0;
      } else 
      {
        Clock[SWITCH[idx][i]]++;
      }
    }
  }
}

int controlWatch(int idx, int cont, int count)
{
  if(isDone()) // basecase 시계가 다 정렬되었다면 재귀종료!
  {
    return count;
  } else if(idx == 10) // 0~9번 스위치까지 있으므로, 10번 스위치까지 왔다는건 불가능한 경우임
  {
    return -1;
  } else if(cont == 3) 
  // 이미 현재 idx번 스위치를 3번눌렀따는건 더이상 누를 필요 없다는 거 다음 스위치로 넘어가자
  {
    return controlWatch(idx + 1, 0, count); 
  }
  pushOrPushBack(1, idx);
  int ans1 = controlWatch(idx, cont + 1, count + 1);
  pushOrPushBack(-1, idx);
  int ans2 = controlWatch(idx + 1, 0, count);
  int ans = min(ans1, ans2);
  if(ans == -1)
  {
    return max(ans1, ans2);
  }
  return ans;
}

/*
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6    
*/

#include <iostream>
#include <cstdio>
using namespace std;

int arr[2000] = {0};
int ans[2000][2000] = {0};
// 아직 답을 안구한것은 0, 펠린드롬이면 1, 펠린드롬 아니면 -1
int find(int start, int end);

int main()
{
  int n, s, e, m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d", &s, &e);
    int tmp = find(s - 1, e - 1);
    if(tmp == 1)
    {
      printf("1\n");
    } else 
    {
      printf("0\n");
    }
  }
  return 0;
}

int find(int s, int e)
{
  if(ans[s][e] != 0)
  {
    return ans[s][e];
  } else if(s == e) // 한글자는 무조건 펠린드롬
  {
    ans[s][e] = 1;
    return 1;
  } else if(s + 1 == e) // 두글자는 절대 펠린드롬 아님. <- 이부분이 틀렸네 두글자도 펠린드롬 가능함. 
  {
    if(arr[s] == arr[e]) // 펠린드롬인경우
    {
      ans[s][e] = 1;
      return 1;
    } else // 펠린드롬 아닌경우
    {
      ans[s][e] = -1;
      return -1;
    }
  } else // 3글자 이상으로 주어진거지
  {
    if(find(s + 1, e - 1) == 1)
    { // 맨 앞, 뒤 글자 떼고 펠린드롬이면서
      if(arr[s] == arr[e]) // 앞 뒤 글자가 같을때만 펠린드롬이고
      {
        ans[s][e] = 1;
        return 1;
      }
    }
    // 나머지 경우들은 절대 펠린드롬 아님. 
    ans[s][e] = -1;
    return -1;
  }
}

/*
두글자일때는 무조건 펠린드롬 아니라고 단순하게 생각했다가 틀렸네. 
두글자일때도 두개가 같은 글자면 펠린드림이지. 
암튼 다이나믹으로 푼건 잘했음. 
*/

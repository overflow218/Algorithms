#include <iostream>
using namespace std;

int arr[10][10] = {0}; // 각 학생별 친구관계를 나타내기 위한 표.
int ithasfriend[10] = {0}; // i학생이 친구와 짝이 지어졌으면 1, 아니면 0;

void push(int x, int y);
int picnic(int idx, int count, int n);
// idx는 현재 보고있는 친구 번호, count 는 남은 짝없는 친구 수, n은 전체 친구수
void reset(); // arr와 ithasfriend를 초기화 해주는 함수.

int main()
{
  int c; // 전체 테스트 케이스의 수
  int n, m; // 학생의 수, 친구쌍의 수
  cin >> c;
  for(int i = 0; i < c; i++)
  {
    cin >> n;
    cin >> m;
    int tmp1, tmp2;
    for(int i = 0; i < m; i++)
    {
      cin >> tmp1;
      cin >> tmp2;
      push(tmp1, tmp2);
    }
    int ans = picnic(0, n, n);
    cout << ans << '\n';
    reset();
  }
}

void reset()
{
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      arr[i][j] = 0;
    }
    ithasfriend[i] = 0;
  }
}

void push(int x, int y)
{
  if(x < y)
  {
    arr[x][++arr[x][0]] = y;
  } else 
  {
    arr[y][++arr[y][0]] = x;
  }
}


int picnic(int idx, int count, int n) 
{
  if(count == 0) // 모두 짝이 지어진 경우
  {
    return 1;
  }else if(idx == n - 1) // 마지막까지 왔는데, 짝을 못지은 경우
  {
    return 0;
  }else if(ithasfriend[idx] == 1) // 이미 idx가 다른 친구와 짝 지어진 경우
  {
    return picnic(idx + 1, count, n);
  }
  int ans = 0;
  for(int i = 1; i <= arr[idx][0]; i++)
  {
    if(ithasfriend[idx] == 0 && ithasfriend[arr[idx][i]] == 0)
    {
      ithasfriend[idx] = 1;
      ithasfriend[arr[idx][i]] = 1;
      ans += picnic(idx + 1, count - 2, n);
      ithasfriend[idx] = 0;
      ithasfriend[arr[idx][i]] = 0; 
    }
  }
  return ans;
}

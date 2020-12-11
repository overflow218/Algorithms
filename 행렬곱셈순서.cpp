#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int matrix[500][2] = {0}; // 행렬 담아놓는곳
int ans[500][500] = {0};
// ans[i][j] 는 i번 행렬부터 j번 행렬까지 곱했을때의 최소 곱셉 연산횟수

int find(int start, int end);

int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &matrix[i][0], &matrix[i][1]);
  }
  find(0, n - 1);
  printf("%d\n", ans[0][n - 1]);
  return 0;
}

int find(int start, int end)
{
  if(ans[start][end] != 0)
  {
    return ans[start][end];
  } else if(start == end)
  {
    ans[start][end] = 0;
    return 0;
  } else if(start + 1 == end)
  {
    ans[start][end] = matrix[start][0] * matrix[start][1] * matrix[end][1];
    return ans[start][end];
  } else 
  {
    int tmp = INT_MAX;
    for(int i = start; i < end; i++)
    {
      int pmul = matrix[start][0] * matrix[i][1] * matrix[end][1];
      tmp = min(tmp, find(start, i) + find(i + 1, end) + pmul);
    }
    ans[start][end] = tmp;
    return tmp;
  }
}

/*
이전에 파일 합치기 답을 봤더니
그 방식으로 풀어야한다는게 딱 보였다. 
역시 이래서 모르면 답을 보고 
곱씹어서 이해한뒤, 다시 풀어보는게 중요하다.
*/

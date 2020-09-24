#include <iostream>
#include <vector>
using namespace std;

int f(int * & fence, int start, int end);
/*
 울타리를 받아서 start부터 end까지 잘라서 만들 수 있는 직사각형의 최대넓이를 구하는 함수. 
 맨첨에 0 ~~~ (n-1) 까지 있을때 이걸 반으로 나눠서 왼쪽 오른쪽으로 나눈다고 해보자.
 그러면 최대 넓이를 가지는 직사각형이 
 1. 반으로 나눈 왼쪽에 있다.
 2. 반으로 나눈 오른쪽에 있다.
 3. 왼쪽과 오른쪽에 걸쳐있다. 
 이렇게 3가지 경우로 나눌수 있다.
 재귀 함수로 돌릴경우 basecase는 start == end인 경우이다.
 그게 아닌경우 1번 경우 구하고, 2번 경우 구하고 그중에 큰거랑 3번에서 구한거 중에 큰거가 리얼 정답이 된다.
 즉 max(ans3, max(ans1, ans2)) 라고 생각하면 된다. 
 ans1 이랑 ans2는 그냥 범위줄여서 재귀 돌리면 되는거고 ans3구하는 거만 코드를 짜면 될것같다.
 근데 생각해보면 3번 경우에는 무조건 왼쪽의 맨 오른쪽 울타리와 오른쪽의 맨 왼쪽 울타리가 포함된다.
 즉 start ~ mid// 왼쪽
  mid + 1 ~  end // 오른쪽 이라고 하면
  mid 와 mid+1 번 울타리는 무조건 포함된다.
  여기서부터 좌우로 쭉 가면서 최대인거 찾아서 리턴하면 그게 case3의 최대넓이가 된다.
*/


int main()
{
  int c; // 테스트 케이스의 갯수
  cin >> c;
  int * a = new int[c];
  for(int i = 0; i < c; i++)
  {
    int n; // 테스트 케이스별 판자의 수
    cin >> n;
    int * fence = new int [n]; // fence의 순서별 높이를 나타내는 배열
    for(int j = 0; j < n; j++)
    {
      cin >> fence[j];
    }
    int ans = f(fence, 0, n - 1);
    a[i] = ans;
    delete[] fence;
  }
  for(int i = 0; i < c; i++)
  {
    cout << a[i] << '\n';
  }
  delete[] a;
  return 0;
}

int f(int * & fence, int start, int end)
{
  if(start == end)
  {
    return fence[start];
  }
  int ans; // 진짜 답
  int mid = (start + end) / 2;
  int ans1 = f(fence, start, mid); //왼쪽 부분의 최대크기
  int ans2 = f(fence, mid + 1, end); // 오른쪽 부분의 최대크기
  ans = max(ans1, ans2);

  //3번 케이스를 구하기 위한 과정. 
  int low = mid;
  int high = mid + 1;
  int height = min(fence[low], fence[high]); // 넓이 구할때 쓸 임시 높이. 
  ans = max(ans, height * 2);
  while (low > start || high < end)
  {
    if(high < end &&(low == start || fence[low - 1] < fence[high + 1])) 
    // 오른쪽 울타리를 골라야하는 경우
    {
      high++;
      height = min(height, fence[high]);
    } else // 왼쪽 울타리를 골라야하는 경우
    {
      low--;
      height = min(height, fence[low]);
    }
    // 과정마다 반복해서 넓이비교해서 큰거로 바꿔줌. 
    ans = max(ans, height * (high - low + 1));
  }
  return ans;
}

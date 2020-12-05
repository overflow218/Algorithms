#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int big = -1000000000;
int small = 1000000000;

void ans(deque<int> number, deque<int> factor);

int main()
{
  int n;
  int tmp;
  deque <int> number; // 수를 담고 있는 덱
  deque <int> factor; // 연산자를 담고 있는 덱
  // 0 1 2 3 이 순서대로 더하기, 빼기, 곱하기 , 나누기를 의미한다.
  // + - * /

  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &tmp);
    number.push_back(tmp);
  }
  for(int i = 0; i < 4; i++)
  {
    scanf("%d", &tmp);
    for(int j = 0; j < tmp; j++)
    {
      factor.push_back(i);
    }
  }
  ans(number, factor);
  printf("%d\n%d\n", big, small);
}

void ans(deque<int> number, deque<int> factor)
{
  if(number.size() == 1)
  {
    int x = number[0];
    if(x >= big)
    {
      big = x;
    }
    if(x <= small)
    {
      small = x;
    } 
  } else
  {
    int len = factor.size();
    for(int i = 0; i < len; i++)
    {
      int fac = factor[0];
      factor.pop_front();
      // 현재 연산자를 계산하고 다음으로 넘어가기
      int a = number[0];
      int b = number[1];
      number.pop_front();
      number.pop_front();
      int tmp;
      switch(fac)
      {
        case 0:
          tmp = a + b;
          break;
        case 1:
          tmp = a - b;
          break;
        case 2:
          tmp = a * b;
          break;
        default:
          tmp = a / b;
          break;
      }
      number.push_front(tmp);
      ans(number, factor); // 계산하고 부르기 
      factor.push_back(fac);
      number.pop_front();
      number.push_front(b);
      number.push_front(a);
    }
  }
}

/*
알고리즘문제를 풀때는 하나의 사소한 실수도 정답과 오답을 가른다는 것을 다시 한번 느꼈다.
논리를 잘 세웠다 생각하고 실행해봤는데, 44%에서 틀렸다. 알고보니 if문을 써야할 곳에 else if 문을
써서 그랬던 것이었다. 조심하고 다음부터는 이런 실수를 하지 않도록 하자.
*/

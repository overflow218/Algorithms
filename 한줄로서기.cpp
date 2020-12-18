#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  int n;
  int arr[10] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  vector <int> q(10, 0);
  vector <int> :: iterator it;
  for(int i = n - 1; i >= 0; i--)
  {
    it = q.begin();
    q.insert(it + arr[i], i);
  }
  for(int i = 0; i < n; i++)
  {
    printf("%d ", q[i] + 1);
  }
  return 0;
}

/*
키가 큰 순서부터 차례대로 넣어주면 쉽게 해결할 수 있음.
ex) n = 4 일때
1번은 자기보다 키 큰사람이 3명인데, 입력으로 주어진건 2명이므로 
3번째 자리에 들어가면 된다.
*/

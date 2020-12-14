#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, k;
int ans = 1000000; // 일부러 대빵 큰수 넣어놈. 
int visited[100001] = {0};


void find(queue<int> & q, int count);

int main()
{
  scanf("%d %d", &n, &k);
  queue<int> q;
  q.push(n);
  find(q, 0);
  printf("%d\n", ans);
  return 0;
}

void find(queue<int> & q, int count)
{
  int len = q.size();
  int tmp;
  for(int i = 0; i < len; i++)
  {
    tmp = q.front();
    if(tmp == k)
    {
      ans = count;
      return;
    }
    q.pop();
    visited[tmp] = 1;
    if(tmp - 1 >= 0 && visited[tmp -1] == 0)
    {
      q.push(tmp-1);
    }
    if(tmp + 1 <= 100000 && visited[tmp + 1] == 0)
    {
      q.push(tmp +1);
    }
    if(tmp * 2 <= 100000 && visited[tmp * 2] == 0)
    {
      q.push(tmp *2);
    }
  }
  find(q, count + 1);
}

/*
숨바꼭질 문제였습니다.
*/

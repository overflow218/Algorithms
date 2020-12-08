#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void find(int start, int end, int target, int * &arr);

int main()
{
  int n, m;
  scanf("%d", &n);
  int * arr = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    find(0, n - 1, tmp, arr);
  }
  return 0;
}

void find(int start, int end, int target, int *&arr)
{
  if(start >= end)
  {
    if(arr[start] == target)
    {
      printf("1 ");
    } else 
    {
      printf("0 ");
    }
  } else
  {
    int mid = (start + end) / 2;
    if(arr[mid] == target)
    {
      printf("1 ");
      return;
    } else if(arr[mid] < target)
    {
      start = mid + 1;
      return find(start, end, target, arr);
    } else
    {
      end = mid - 1;
      return find(start, end, target, arr);
    }
  }
}

/*
이분탐색 감잡은게 맞는지 확인하기 위해서
몇문제 더 풀어보려고 합니다. 
이 이분탐색에서 범위 줄일때
start = mid + 1;
end = mid - 1; 
이렇게 돌아야 무한루프에 빠지는 걸 막아줄 수 있습니다.
또한 
while(start < end) 의 조건으로 돌아야 하며
마지막 확인은 start로 해야합니다. 
start = mid + 1;
end = mid - 1; 
이렇게 가게되면 end 는 start - 1로 될수 있지만
start는 end 까지밖에 갈 수 없습니다. 
즉 start만이 안전한 인덱스라는게 보장되니깐 이렇게 해야 합니다.
무슨말인지 다시 풀어보면 이해가 갈 것입니다. 
이분탐색이 개념은 어렵지 않은데 실제로 구현하다보면, 
크고 작은부분의 세밀하지 못함으로 인해 무한루프에 빠진다든지 segmentation fault등에 
빠지는 경우가 많은데 그런 디테일에 신경쓰도록 합시다.
*/

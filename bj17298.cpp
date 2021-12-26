#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

// 여기에 <idx, value>를 담아서 넣어줄거임 
stack<pair<int, int>> s;
int arr[1000001];

int main()
{
	int n, tmp;
	scanf("%d", &n);
	memset(arr, -1, sizeof(int) * (n + 1));
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		// 스택에 원소가 남아 있으면서, 맨위의 원소보다 tmp가 큰동안 스택을 반복해서 비워준다.
		while(!s.empty() && s.top().second < tmp)
		{
			arr[s.top().first] = tmp;
			s.pop();
		}
		s.push(pair<int, int>(i, tmp));
	}	
	
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

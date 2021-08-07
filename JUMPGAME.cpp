#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 문제에서 주어지는 게임판
int arr[100][100];
//isAvailable[i][j] =  arr[i][j]에서 시작해서 arr[n-1][n-1]칸까지 갈수있으면 1, 아직 모르면 -1, 
// 불가능하면 0을 담는다.
int isAvailable[100][100] = {false};
// 테스트 케이스의 수, 격자의 크기
int c, n;
// 각 테스트 케이스 별로 도달가능한 답을 찾았는지의 여부
bool isDone = false;

// arr[x][y]에서 시작해서 arr[n-1][n-1]에 도달할 수 있으면 1, 아니면 -1을 반환함.
int jump(int x, int y)
{
	//basecase 1. 범위를 벗어나는 경우
	if(x >= n || y >= n)
	{
		return 0;
	}
	//basecase 2. 이미 도달가능한 답을 찾았거나 마지막 칸에 도달한 경우
	else if(isDone || (x == n - 1 && y == n - 1))
	{
		isDone = true;
		return 1;
	}

	int & ret = isAvailable[x][y];
	// 이미 방문했던 칸이면 바로 종료
	if(ret != -1)
	{
		return ret;
	}
	// 그 이외의 경우 아래로 내려가는 경우와 오른쪽으로 가는 경우를 모두 살피면 된다.
	return ret = jump(x + arr[x][y], y) | jump(x, y + arr[x][y]);
}

int main()
{
	scanf("%d", &c);
	for(int t = 0; t < c; t++)
	{
		// 테스트 케이스별 격자의 크기 입력받기
		scanf("%d", &n);
		// 전역 변수들 초기화 시켜주기
		memset(isAvailable, -1, sizeof(isAvailable));
		isDone = false;
		// 게임판 입력받기
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		// 도달할 수 있는 경우
		if(jump(0, 0))
		{
			printf("YES\n");
		}
		// 도달할 수 없는 경우
		else 
		{
			printf("NO\n");
		}
	}
	return 0;
}

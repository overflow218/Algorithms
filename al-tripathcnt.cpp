#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int triangle[100][100] = {0};
// (i,j)부터 마지막줄까지 내려갔을때의 최대 합을 표현
int sum[100][100] = {0};
// (i,j)부터 마지막줄까지 내려갔을때의 최대 경로의 수를 표현
int cnt[100][100] = {0};

// 1. 일단 삼각형 위의 최대 경로합을 구하는 문제를 먼저 해결
// 2. 1의 결과를 바탕으로 최대 경로 수를 구하는 문제를 다시 해결
int c, n;

int findSum(int x, int y)
{
    int & ret = sum[x][y];
    if(ret) return ret;
    if(x == n - 1) return ret = triangle[x][y];
    return ret = max(findSum(x + 1, y), findSum(x + 1, y + 1)) + triangle[x][y];
}

int findCnt(int x, int y)
{
    if(x == n - 1) return 1;
    int & ret = cnt[x][y];
    if(ret) return ret;
    if(sum[x + 1][y] >= sum[x + 1][y + 1]) ret += findCnt(x + 1, y);
    if(sum[x + 1][y] <= sum[x + 1][y + 1]) ret += findCnt(x + 1, y + 1);
    return ret;
}

int main()
{
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d", &n);
        memset(triangle, 0, sizeof(triangle));
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                scanf("%d", &triangle[i][j]);
            }
        }
        findSum(0, 0);
        printf("%d\n", findCnt(0, 0));
    }
}

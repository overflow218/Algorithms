#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c, n;
int triangle[100][100] = {0};
// (i, j)에서 맨 아랫줄까지 갈때까지 최대합. 아직 안구했으면 0, 구했으면 구한 값
int cache[100][100] = {0};

int find(int x, int y)
{
    if(x == n -1) return triangle[x][y];
    int & ret = cache[x][y];
    if(ret) return ret;
    return ret = triangle[x][y] + max(find(x + 1, y), find(x + 1, y + 1));
}

int main()
{
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d", &n);
        memset(cache, 0, sizeof(cache));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                scanf("%d", &triangle[i][j]);
            }
        }
        printf("%d\n", find(0, 0));
    }
    return 0;
}
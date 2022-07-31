#include <iostream>
#include <cstdio>
using namespace std;

int dx1[] = {0, 0, 0, 0};
int dy1[] = {0, 1, 2, 3};

int dx2[] = {0, 0, 1, 1};
int dy2[] = {0, 1, 0, 1};

int dx3[] = {0, 1, 2, 2};
int dy3[] = {0, 0, 0, 1};

int dx4[] = {0, 0, 1, 1};
int dy4[] = {0, 1, 1, 2};

int dx5[] = {0, 0, 0, 1};
int dy5[] = {0, 1, 2, 1};

int ans = 0, n, m;
int arr[500][500] = {0};

int dx[][5] = {{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 2, 2}, {0, 0, 1, 1}, {0, 0, 0, 1}};
int dy[][5] = {{0, 1, 2, 3}, {0, 1, 0, 1}, {0, 0, 0, 1}, {0, 1, 1, 2}, {0, 1, 2, 1}};

void go(int x, int y, int type)
{
    for(int i = 0; i < 4; i++)
    {
        if(x + dx[type][i] < 0 || x + dx[type][i] >= n || y + dy[type][i] < 0 || y + dy[type][i] >= m) return;
    }
    int tmp = 0;
    for(int i = 0; i < 4; i++)
    {
        tmp += arr[x + dx[type][i]][y + dy[type][i]];
    }
    ans = max(ans, tmp);
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                go(i, j, k);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
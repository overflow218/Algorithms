#include <iostream>
#include <cstring>
using namespace std;

int cur[50][50];
int tmp[50][50];
int r, c, t, r1 = -1, r2 = -1;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void diffuse(int x, int y)
{
    if(cur[x][y] <= 0) return;
    tmp[x][y] += cur[x][y];
    int diffusionAmount = cur[x][y] / 5;
    if(diffusionAmount > 0)
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx == r || ny < 0 || ny == c) continue;
            if(ny == 0 && (nx == r1 || nx == r2)) continue;
            tmp[nx][ny] += diffusionAmount;
            tmp[x][y] -= diffusionAmount;
        }
    }
}

void airClean()
{
    // 1. 위쪽 돌리기
    for(int row = r1 - 1; row >= 0; row--)
    {
        cur[row + 1][0] = cur[row][0];
    }
    for(int col = 1; col < c; col++)
    {
        cur[0][col - 1] = cur[0][col];
    }
    for(int row = 1; row <= r1; row++)
    {
        cur[row - 1][c - 1] = cur[row][c - 1];
    }
    for(int col = c - 2; col >= 1; col--)
    {
        cur[r1][col + 1] = cur[r1][col];
    }

    // 아래쪽 돌리기
    for(int row = r2 + 1; row < r; row++)
    {
        cur[row - 1][0] = cur[row][0];
    }
    for(int col = 1; col < c; col++)
    {
        cur[r - 1][col - 1] = cur[r - 1][col];
    }
    for(int row = r - 2; row >= r2; row--)
    {
        cur[row + 1][c - 1] = cur[row][c - 1];
    }
    for(int col = c - 2; col >= 1; col--)
    {
        cur[r2][col + 1] = cur[r2][col];
    }

    cur[r1][1] = 0;
    cur[r2][1] = 0;
    cur[r1][0] = -1;
    cur[r2][0] = -1;
}
int main()
{
    scanf("%d %d %d", &r, &c, &t);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &cur[i][j]);
            if(cur[i][j] == -1)
            {
                if(r1 == -1)
                {
                    r1 = i;
                } else 
                {
                    r2 = i;
                }
            }
        }
    }
    int cnt = 0;
    while(cnt < t)
    {
        memset(tmp, 0, sizeof(tmp));
        // 1. 먼지확산
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                diffuse(i, j);
            }
        }
        memcpy(cur, tmp, sizeof(cur));
        //2. 공기청정기
        airClean();
        cnt++;
    }

    int ans = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(cur[i][j] > 0)
            {
                ans += cur[i][j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
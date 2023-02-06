#include <iostream>
#include <cstring>
using namespace std;

int m, n;
int board[500][500] = {0};
int cache[500][500] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int find(int x, int y)
{
    if(x == m - 1 && y == n - 1) return 1;

    int &ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx == m || ny < 0 || ny == n || board[x][y] <= board[nx][ny]) continue;
        ret += find(nx, ny);
    }
    return ret;
}
int main()
{
    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    memset(cache, -1, sizeof(cache));
    printf("%d\n", find(0, 0));
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int arr[500][500];
int cache[500][500];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, ans = 0;

int panda(int x, int y)
{
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx == n || ny < 0 || ny == n || arr[nx][ny] <= arr[x][y]) continue;
        ret = max(ret, panda(nx, ny));
    }
    ret = ret + 1;
    ans = max(ans, ret);
    return ret;
}

int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(cache[i][j] == -1)
            {
                panda(i, j);
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
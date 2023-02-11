#include <iostream>
using namespace std;

int n, m, ans = 0;
char arr[1000][1010];
int cache[1000][1000] = {0};

int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};

int find(int x, int y)
{
    int &ret = cache[x][y];
    if(arr[x][y] == '0' || ret != 0) return ret;
    // 이제 0인건 없음
    if(x == n - 1 || y == m - 1) 
    {
        ans = max(ans, 1);
        return 1;
    }

    int check = 1001;
    for(int i = 0; i < 3; i++)
    {
        check = min(check, find(x + dx[i], y + dy[i]));
    }
    ret = check + 1;
    ans = max(ans, ret);
    return ret;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j]== '1')
            {
                find(i, j);
            }
        }
    }

    cout << ans * ans << '\n';
    return 0;
}
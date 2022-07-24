#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n, m, h, ans = 0;
int tomato[100][100][100] = {0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};


class point{
    public:
        int x;
        int y;
        int z;
        int cnt;
    point(int x, int y, int z, int cnt) {
        this -> x = x;
        this -> y = y;
        this -> z = z;
        this -> cnt = cnt;
    }
};
queue<point> q;

int main()
{
    scanf("%d %d %d", &m, &n, &h);
    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &tomato[i][j][k]);
                if(tomato[i][j][k] == 1)
                {
                    for(int a = 0; a < 6; a++)
                    {
                        q.push(point(i + dx[a], j + dy[a], k + dz[a], 1));
                    }
                }
            }
        }
    }

    while(!q.empty())
    {
        point tmp_point = q.front();
        q.pop();
        int x = tmp_point.x, y = tmp_point.y, z = tmp_point.z, cnt = tmp_point.cnt;
        if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h) continue;
        if(tomato[x][y][z] == 0)
        {
            tomato[x][y][z] = cnt;
            ans = max(ans, cnt);
            for(int i = 0; i < 6; i++)
            {
                q.push(point(x + dx[i], y + dy[i], z + dz[i], cnt+ 1));
            }
        }
    }
    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(tomato[i][j][k] == 0)
                {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    printf("%d\n", ans);
}
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n, m, ans = 0;
int tomato[1000][1000] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class point{
    public:
        int x;
        int y;
        int cnt;
    point(int x, int y, int cnt) {
        this -> x = x;
        this -> y = y;
        this -> cnt = cnt;
    }
};
queue<point> q;

int main()
{
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j] == 1)
            {
                for(int k = 0; k < 4; k++)
                {
                    q.push(point(i + dx[k], j + dy[k], 1));
                }
            }
        }
    }

    while(!q.empty())
    {
        point tmp_point = q.front();
        q.pop();
        int x = tmp_point.x, y = tmp_point.y, cnt = tmp_point.cnt;
        if(x < 0 || x >= n || y < 0 || y >= m) continue;
        if(tomato[x][y] == 0)
        {
            tomato[x][y] = cnt;
            ans = max(ans, cnt);
            for(int i = 0; i < 4; i++)
            {
                q.push(point(x + dx[i], y + dy[i], cnt+ 1));
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(tomato[i][j] == 0)
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", ans);
}
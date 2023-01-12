#include<iostream>
#include <queue>
#include <vector>
using namespace std;

char arr[1000][1001] = {0};
bool isVisited[2][1000][1001] = {false};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    // (x, y, 현재거리, 부신 벽 개수)
    queue<vector<int>> q;
    q.push({0, 0, 0});
    int ans = 0;
    while(!q.empty())
    {
        ans++;
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            vector<int> tmp = q.front();
            q.pop();
            int x = tmp[0], y = tmp[1], wall = tmp[2];
            if(x < 0 || x == n || y < 0 || y == m || isVisited[wall][x][y] || (arr[x][y] == '1' && wall == 1)) continue;

            if(x == n - 1 && y == m - 1)
            {
                printf("%d\n", ans);
                return 0;
            }

            isVisited[wall][x][y] = true;
            int nextWall = arr[x][y] == '1' ? wall + 1 : wall;

            for(int i = 0; i < 4; i++)
            {
                vector<int> ho = {x + dx[i], y + dy[i], nextWall};
                q.push(ho);
            }
        }
    }
    printf("-1\n");
    return 0;
}
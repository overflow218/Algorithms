#include <string>
#include <vector>
#include <queue>
using namespace std;

struct point
{
    int x;
    int y;
    int direction;
    int cost;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cache[2][25][25];
queue<point> q;
int solution(vector<vector<int>> board)
{
    int n = board.size();
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                cache[i][j][k] = 100000000;
            }
        }
    }
    cache[0][0][0] = 0;
    cache[1][0][0] = 0;
    q.push(point{0, 1, 1, 100});
    q.push(point{1, 0, 0, 100});

    while (!q.empty())
    {
        point tmp = q.front();
        q.pop();
        int x = tmp.x, y = tmp.y, direction = tmp.direction, cost = tmp.cost;
        // 범위 벗어나는 경우 컷
        if (x < 0 || x == n || y < 0 || y == n)
            continue;

        // 벽이거나 이전에 더 작은 비용, 같은 방향으로 방문했던 경우 컷
        if (board[x][y] == 1 || cache[direction % 2][x][y] <= cost)
            continue;
        cache[direction % 2][x][y] = cost;

        // 끝점 도착했으면 종료
        if (x == n - 1 && y == n - 1)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int newCost = (direction % 2) == (i % 2) ? 100 : 600;
            q.push({x + dx[i], y + dy[i], i, cost + newCost});
        }
    }

    int ans = min(cache[0][n - 1][n - 1], cache[1][n - 1][n - 1]);
    return ans;
}
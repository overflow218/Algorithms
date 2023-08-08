#include <iostream>
#include <queue>
using namespace std;

char board[50][52] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool isVisited[50][50] = {false};
int n, m, ans = 0;

queue<pair<int, int>> q;
void find(int x, int y, int cnt)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(board[x][y] == 'H')
    {
        ans = max(ans, cnt);
        return;
    }

    isVisited[x][y] = true;
    
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", board[i]);
    }

    q.push(make_pair(0, 0));
    int step = 0;
    while(!q.empty())
    {
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(isVisited[x][y]) continue;
            int go = board[x][y] - '0';
            isVisited[x][y] = true;
            for(int j = 0; j < 4; j++)
            {
                int nx = x + dx[j] * go, ny = y + dy[j] * go;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == 'H') continue;
                if(isVisited[nx][ny])
                {
                    printf("-1\n");
                    return 0;
                }
                q.push(make_pair(nx, ny));
            }
        }
        step++;
    }

    printf("%d\n", step);
    return 0;
}
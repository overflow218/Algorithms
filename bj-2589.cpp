#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

char board[51][51] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    int h, w, ans = 0;
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; i++)
    {
        scanf("%s", board[i]);
    }
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(board[i][j] == 'L')
            {
                q.push(make_pair(make_pair(i, j), 0));
                vector<vector<bool>> isVisited(h, vector<bool>(w, false));
                while(!q.empty())
                {
                    auto current = q.front();
                    q.pop();
                    int x = current.first.first, y = current.first.second, dist = current.second;
                    if(x < 0 || x == h || y < 0 || y == w || isVisited[x][y] || board[x][y] == 'W') continue;
                    ans = max(ans, dist);
                    isVisited[x][y] = true;
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k], ny = y + dy[k];
                        q.push(make_pair(make_pair(nx, ny), dist + 1));
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
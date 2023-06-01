#include <queue>
class Solution {
public:
    queue<pair<int, int>> q;
    bool isVisited[100][100] = {false};
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        q.push(make_pair(0, 0));
        int cnt = 1;
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        while(!q.empty())
        {
            int limit = q.size();
            for(int i = 0; i < limit; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x == n - 1 && y == n - 1) return cnt;
                if(x < 0 || x == n || y < 0 || y == n || grid[x][y] == 1 || isVisited[x][y]) continue;
                isVisited[x][y] = true;
                for(int j = 0; j < 8; j++)
                {
                    int nx = x + dx[j], ny = y + dy[j];
                    q.push(make_pair(nx, ny));
                }
            }
            cnt++;
        }
        return -1;
    }
};

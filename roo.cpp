#include <queue>

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        bool isDeleted[10][10] = {false};
        queue<pair<int, int>> q;

        int fresh = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n ;j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                } else if(grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        if(fresh == 0) return 0;
        int stage = -1;
        while(!q.empty())
        {
            int limit = q.size();
            stage++;
            for(int i = 0; i < limit; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x < 0 || x == m || y < 0 || y == n || isDeleted[x][y]) continue;
                
                if(grid[x][y] == 0) continue;
                if(grid[x][y] == 1) fresh--;
                isDeleted[x][y] = true;
                for(int j = 0; j < 4; j++)
                {
                    q.push(make_pair(x + dx[j], y + dy[j]));
                }
            }
            if(fresh <= 0) break;
        }
        return fresh == 0 ? stage : -1;
    }
};
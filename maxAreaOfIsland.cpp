class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n = 0, m = 0;

    int dfs(int x, int y, int flag, vector<vector<int>>& grid)
    {
        if(x < 0 || x == n || y < 0 || y == m || grid[x][y] != 1)
        {
            return 0;
        }
        int cnt = 1;
        grid[x][y] = flag;
        for(int i = 0;i < 4; i++)
        {
            cnt += dfs(x + dx[i], y + dy[i], flag, grid);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        int flag = 2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans, dfs(i, j, flag++, grid));
                }
            }
        }
        return ans;
    }
};
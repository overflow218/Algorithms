class Solution {
public:
    const int MOD = 1000000007;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int cache[1000][1000] = {0};
    int m, n;
    int find(int x, int y, vector<vector<int>>& grid)
    {
        if(x < 0 || x == m || y < 0 || y == n) return 0;
        int &ret = cache[x][y];
        if(ret != 0) return ret;
        ret = 1;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
            if(grid[x][y] >= grid[nx][ny]) continue;
            ret = (ret + find(nx, ny, grid)) % MOD;
        }
        return ret;
    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(cache[i][j] == 0) find(i, j, grid);
                ans = (ans + cache[i][j]) % MOD;
            }
        }
        return ans;
    }
};
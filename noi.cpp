class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isVisited[300][300];
    int n;
    int m;
    void check(int x, int y, vector<vector<char>>& grid)
    {
        if(x < 0 || x == m || y < 0 || y == n || grid[x][y] == '0' || isVisited[x][y]) return;
        isVisited[x][y] = true;
        
        for(int i = 0; i < 4; i++)
        {
            check(x + dx[i], y + dy[i], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && !isVisited[i][j])
                {
                    ans++;
                    check(i, j, grid);
                }
            }
        }

        return ans;
    }
};
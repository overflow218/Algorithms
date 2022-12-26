class Solution {
public:
    bool isVisited[300][300] = {0};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] == '0' || isVisited[x][y]) return;
        isVisited[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            dfs(x + dx[i], y + dy[i], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!isVisited[i][j] and grid[i][j] == '1')
                {
                    ans += 1;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
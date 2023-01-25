class Solution {
public:
    bool isVisited[500][500] = {false};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;
    bool flag;
    // grid2 에 있는게 grid1에 있어야함. 
    void isPossible(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        if(x < 0 || x == m || y < 0 || y == n || isVisited[x][y]) return;
        isVisited[x][y] = true;
        if(!grid1[x][y] && grid2[x][y])
        {
            flag = false;
        }
        if(grid2[x][y])
        {
            for(int i = 0; i < 4; i++)
            {
                isPossible(x + dx[i], y + dy[i], grid1, grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        m = grid1.size();
        n = grid1[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid2[i][j] == 1 && !isVisited[i][j])
                {
                    flag = true;
                    isPossible(i, j, grid1, grid2);
                    if(flag)
                    {
                        ans++;
                        // printf("%d, %d 에서 늘어났음\n", i, j);
                    }
                }
            }
        }
        
        return ans;
    }
};
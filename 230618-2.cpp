class Solution {
public:
    int cache[200][200] = {0};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;

    int find(int x, int y, vector<vector<int>>& matrix)
    {
        
        if(x < 0 || x == m || y < 0 || y == n) return 0;
        int &ret = cache[x][y];
        if(ret != 0) return ret;
        ret = 1;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
            if(matrix[nx][ny] <= matrix[x][y]) continue;
            ret = max(ret, 1 + find(nx, ny, matrix));
        }
        return ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans = max(ans, find(i, j, matrix));
            }
        }
        return ans;
    }
};
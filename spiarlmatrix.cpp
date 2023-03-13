class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool isVisited[10][10] = {false};
    int n, m;
    void visit(int x, int y, int direction, vector<vector<int>>& matrix, vector<int> &chosen)
    {
        isVisited[x][y] = true;
        chosen.push_back(matrix[x][y]);
        for(int i = 0; i < 4; i++)
        {
            int d = (direction + i) % 4;
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx == m || ny < 0 || ny == n || isVisited[nx][ny]) continue;
            return visit(nx, ny, d, matrix, chosen);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<int> ans;
        visit(0, 0, 0, matrix, ans);
        return ans;
    }
};
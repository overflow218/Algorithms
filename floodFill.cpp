class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(vector<vector<int>>& image, int x, int y, int from, int color) {
        if(x < 0 || x == image.size() || y < 0 || y == image[0].size() || image[x][y] == color || image[x][y] != from) return;
        image[x][y] = color;
        for(int i = 0; i < 4; i++)
        {
            dfs(image, x + dx[i], y + dy[i], from, color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
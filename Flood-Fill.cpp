class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void change(int x, int y, int original, int color, vector<vector<int>>& image)
    {
        int m = image.size(), n = image[0].size();
        if(x < 0 || x == m || y < 0 || y == n || image[x][y] != original) return;
        image[x][y] = color;
        for(int i = 0; i < 4; i++)
        {
            change(x + dx[i], y + dy[i], original, color, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
        {
            change(sr, sc, image[sr][sc], color, image);
        }
        return image;
    }
};
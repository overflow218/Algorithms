#include <algorithm>
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++)
        {
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }
        for(int i = 0; i < col; i++)
        {
            int tmp = 0;
            for(int j = 0; j < row; j++)
            {
                tmp = max(tmp, grid[j][i]);
            }
            ans+= tmp;
        }
        return ans;
    }
};
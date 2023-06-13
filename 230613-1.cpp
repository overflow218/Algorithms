class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // 걍 O(n ^ 2)으로 돌리면 될 것 같음 ㅎㅎ
        int ans = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool isGood = true;
                for(int k = 0; k < n; k++)
                {
                    if(grid[i][k] != grid[k][j])
                    {
                        isGood = false;
                        break;
                    }
                }
                if(isGood) ans++;
            }
        }
        return ans;
    }
};
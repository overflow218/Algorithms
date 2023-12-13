class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rowCount[100] = {0};
        int colCount[100] = {0};
        int ans = 0;

        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j])
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] && rowCount[i] == 1 && colCount[j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

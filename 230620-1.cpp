class Solution {
public:
    void zero(bool isRow, int idx, vector<vector<int>>& matrix)
    {
        // idx번째 로우를 0으로 채우기
        if(isRow)
        {   
            for(int i = 0; i < matrix[0].size(); i++)
            {
                matrix[idx][i] = 0;
            }
        } 
        // idx번째 칼럼을 0으로 채우기
        else 
        {
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][idx] = 0;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int origin = matrix[0][0];
        bool zeroCol = false, zeroRow = false;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] != 0) continue;
                matrix[0][j] = matrix[i][0] = 0;
                if(i == 0) zeroRow = true;
                if(j == 0) zeroCol = true;
            }
        }

        for(int i = 1; i < m; i++)
        {
            if(matrix[i][0] == 0) zero(true, i, matrix);
        }
        for(int i = 1; i < n; i++)
        {
            if(matrix[0][i] == 0) zero(false, i, matrix);
        }
        if(zeroRow) zero(true, 0, matrix);
        if(zeroCol) zero(false, 0, matrix);
    }
};
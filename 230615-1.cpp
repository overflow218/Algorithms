/*
0 2n - 1
1 n + 3
2 n + 2
3 n + 1
.. n 
n - 1
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> vec = vector<vector<char>>(numRows);
        string ans = "";
        int idx = 0, flag = 1;
        for(int i = 0; i < s.size(); i++)
        {
            vec[idx].push_back(s[i]);
            if(idx == numRows - 1 && flag == 1) flag = -1;
            if(idx == 0 && flag == -1) flag = 1;
            idx += flag;
        }
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < vec[i].size(); j++)
            {
                ans += vec[i][j];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int col = 0; col < strs[0].size(); col++)
        {
            for(int row = 0; row < strs.size() - 1; row++)
            {
                if(strs[row][col] > strs[row + 1][col])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
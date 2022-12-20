class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int cnt = 0; cnt < strs[0].size(); cnt++)
        {
            for(int idx = 0; idx < strs.size(); idx++)
            {
                if(cnt >= strs[idx].size()) return ans;
                if(strs[idx][cnt] != strs[0][cnt]) return ans;
            }
            ans += strs[0][cnt];
        }
        return ans;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0, idx = 0;
        while(idx < chars.size())
        {
            int cnt = 1;
            while(idx + 1 < chars.size() && chars[idx] == chars[idx + 1])
            {
                cnt++;
                idx++;
            }
            ans = cnt == 1 ? ans + 1 : ans + 2;
            idx++;
        }
        return ans;
    }
};
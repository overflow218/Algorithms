class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> vec;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1) cnt++;
            if(nums[i] == 0)
            {
                if(cnt != 0) vec.push_back(cnt);
                vec.push_back(0);
                cnt = 0;
            }
        }
        if(cnt != 0) vec.push_back(cnt);
        if(vec.size() == 1) return max(0, vec[0] - 1);
        int ans = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            ans = max(ans, vec[i]);
            if(vec[i] == 0 && (i >= 1 && i <= vec.size() - 2)) ans = max(ans, vec[i - 1] + vec[i + 1]);
        }
        return ans;
    }
};
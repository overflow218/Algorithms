#include <cstring>
#include <algorithm>
class Solution {
public:
    int cache[1000][1001];
    vector<vector<int>> vec = vector<vector<int>>(501);

    int find(int idx, int d, vector<int>& nums)
    {
        if(idx == -1)
        {
            int ret = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                ret = max(ret, find(i, d, nums));
            }
            return ret;
        }
        if(idx == nums.size()) return 0;
        int &ret = cache[idx][d];
        if(ret != -1) return ret;
        ret = 1;
        int D = d - 500;
        int next = nums[idx] + D;
        if(0 <= next && next <= 500)
        {
            auto it = upper_bound(vec[next].begin(), vec[next].end(), idx);
            if(it != vec[next].end()) ret = max(ret, 1 + find(*it, d, nums));
        }
        return ret;
    }
    int longestArithSeqLength(vector<int>& nums) {
        memset(cache, -1, sizeof(cache));
        int small = 1000, big = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            small = min(small, nums[i]);
            big = max(big, nums[i]);
            vec[nums[i]].push_back(i);
        }

        int diff = big - small;
        int ans = 0;
        for(int i = 0; i <= diff; i++)
        {
            ans = max(ans, find(-1, 500 - i, nums));
            ans = max(ans, find(-1, 500 + i, nums));
        }
        return ans;
    }
};
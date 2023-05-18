#include <vector>
class Solution {
public:
    vector<int> cache = vector<int>(100, -1);
    int ho(int idx, vector<int>& nums)
    {
        if(idx >= nums.size()) return 0;
        int &ret = cache[idx];
        if(ret != -1) return ret;
        return ret = max(ho(idx + 1, nums), nums[idx] + ho(idx + 2, nums));
    }
    int rob(vector<int>& nums) {
        return ho(0, nums);
    }
};
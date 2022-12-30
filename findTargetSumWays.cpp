#include <cstring>

class Solution {
public:
    int cache[20][2001];
    int dp(int idx, int sum, vector<int>& nums, int target){
        if(idx == nums.size()) return sum == target ? 1 : 0;
        int & ret = cache[idx][sum + 1000];
        if(ret != -1) return ret;
        ret = 0;
        return ret = dp(idx + 1, sum + nums[idx], nums, target) + dp(idx + 1, sum - nums[idx], nums, target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(cache, -1, sizeof(cache));
        return dp(0, 0, nums, target);
    }
};
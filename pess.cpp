#include <cstring>
#include <algorithm>

class Solution {
public:
    int cache[200][20001];
    int find(int idx, int sum, vector<int>& nums)
    {
        if(sum == 0)
        {
            return 1;
        }
        if(idx == nums.size() || sum < 0) return 0;
        int &ret = cache[idx][sum];
        if(ret != -1) return ret;

        ret = max(find(idx + 1, sum - nums[idx], nums), find(idx + 1, sum, nums));
        return ret;
    }

    bool canPartition(vector<int>& nums) {
        memset(cache, -1, sizeof(cache));
        
        int sum = 0;
        for(const int & num: nums)
        {
            sum += num;
        }
        if(sum % 2 == 1) return false;

        int ans = find(0, sum / 2, nums);
        return ans == 1 ? true : false;
    }
};
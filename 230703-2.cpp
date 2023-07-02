#include <cstring>
class Solution {
public:
    int cache[10000];
    const int INF = 20000000;
    int find(int idx, vector<int>& nums)
    {
        if(idx == nums.size() - 1) return 0;
        int &ret = cache[idx];
        if(ret != -1) return ret;
        ret = INF;
        for(int i = 1; i <= nums[idx]; i++)
        {
            if(idx + i >= nums.size()) break;
            ret = min(ret, 1 + find(idx + i, nums));
        }
        return ret;
    }
    int jump(vector<int>& nums) {
        memset(cache, -1, sizeof(cache));
        return find(0, nums);
    }
};
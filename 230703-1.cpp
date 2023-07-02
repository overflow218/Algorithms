#include <cstring>
class Solution {
public:
    int isPossible[10000];
    int big = 0;
    int find(int idx, vector<int> &nums)
    {
        if(idx == nums.size() - 1) return 1;
        int &ret = isPossible[idx];
        if(ret != -1) return ret;
        ret = 0;

        if(idx < big || (idx == big && nums[idx] > 0))
        {
            big = max(big, idx + nums[idx]);
            ret = find(idx + 1, nums);
        }
        return ret;
    }
    bool canJump(vector<int>& nums) {
        memset(isPossible, -1, sizeof(isPossible));
        return find(0, nums);
    }
};
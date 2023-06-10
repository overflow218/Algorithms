#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cache[100000][50000];
    int check(vector<int>& nums, int idx, int p)
    {
        if(p == 0) return 0;
        if(idx >= nums.size()) return 987654321;
        int &ret = cache[idx][p];
        if(ret != -1) return ret;
        ret = check(nums, idx + 1, p);
        if(idx + 1 < nums.size()) ret = min(ret, check(nums, idx + 2, p - 1) + nums[idx + 1] - nums[idx]);
        return ret;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(nums.size() == 0 || p == 0) return 0;
        memset(cache, -1, sizeof(cache));
        sort(nums.begin(), nums.end());
        return check(nums, 0, p);
    }
};
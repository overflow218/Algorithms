#include <cstring>
class Solution {
public:
    int dp[1000];

    int find(int x, vector<int>& cost)
    {
        if(x >= cost.size()) return 0;
        int &ret = dp[x];
        if(ret != -1) return ret;
        return ret = min(find(x + 1, cost), find(x + 2, cost)) + cost[x];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int ans = min(find(0, cost), find(1, cost));
        return ans;
    }
};
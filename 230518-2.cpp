#include <vector>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int>stair = vector<int>(1005, 987654321);
        stair[0] = 0;
        stair[1] = 0;
        for(int i = 0; i < cost.size(); i++)
        {
            stair[i] += cost[i];
            stair[i + 1] = min(stair[i + 1], stair[i]);
            stair[i + 2] = min(stair[i + 2], stair[i]);
        }
        return stair[cost.size()];
    }
};
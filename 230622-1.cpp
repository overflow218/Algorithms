#include <cstring>
class Solution {
public:
    int cache[50000];
    int find(int idx, vector<int>& prices, int fee)
    {
        if(idx == prices.size()) return 0;
        int &ret = cache[idx];
        if(ret != -1) return ret;
        ret = find(idx + 1, prices, fee);
        for(int i = idx + 1; i < prices.size(); i++)
        {
            int diff = prices[i] - prices[idx] - fee;
            if(diff > 0) ret = max(ret, find(i, prices, fee) + diff);
        }
        return ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(cache, -1, sizeof(cache));
        printf("size: %d\n", prices.size());
        // return 0;
        return find(0, prices, fee);
    }
};
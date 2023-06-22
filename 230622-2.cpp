class Solution {
public:
    int free[50000] = {0};
    int hold[50000] = {0};
    int maxProfit(vector<int>& prices, int fee) {
        free[0] = 0; hold[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
        }
        return free[prices.size() - 1];
    }
};
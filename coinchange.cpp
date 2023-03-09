class Solution {
public:
    int find(long long idx, int amount, vector<int>& coins, vector<int> &cache)
    {
        if(idx > (long long)amount) return 987654321;
        if(idx == amount) return 0;
        int &ret = cache[idx];
        if(ret != -1) return ret;
        ret = 987654321;

        for(const int& coin: coins)
        {
            ret = min(ret, 1 + find(idx + coin, amount, coins, cache));
        }
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(10001, -1);
        int ans = find(0, amount, coins, cache);
        return ans >= 987654321 ? -1 : ans;
    }
};
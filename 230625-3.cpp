class Solution {
public:
    int cache[100000] = {0};
    int maximumSum(vector<int>& arr) {
        int ans = -2000000000, tmp = 0;
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            if(tmp >= 0)
            {
                cache[i] = arr[i] + tmp;
                tmp += arr[i];
            }
            if(tmp < 0)
            {
                tmp = arr[i];
                cache[i] = arr[i];
            }
            ans = max(ans, cache[i]);
        }
        tmp = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(tmp >= 0) tmp += arr[i];
            if(tmp < 0) tmp = arr[i];
            if(i + 2 < arr.size()) ans = max(ans, tmp + cache[i + 2]);
        }
        return ans;
    }
};
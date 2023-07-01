#include <cstring>
class Solution {
public:
    // https://leetcode.com/problems/split-array-largest-sum/description/
    vector<int> pSum;
    // idx번부터 k개의 조각으로 쪼갰을때 각 조각의 최댓값을 의미.
    int cache[1001][55];

    int find(int idx, int k)
    {
        if(k == 1) return pSum.back() - pSum[idx - 1];
        int &ret = cache[idx][k];
        if(ret != -1) return ret;

        if(idx == 0)
        {
            ret = max(pSum[0], find(1, k - 1));
            for(int i = 1; i <= pSum.size() - k; i++)
            {
                int tmp =  max(pSum[i], find(i + 1, k - 1));
                // ret = min(ret, max(pSum[i], find(i + 1, k - 1)));
                ret = min(ret, tmp);
                // printf("i: %d, tmp: %d\n", i, tmp);
            }
        }
        if(idx > 0)
        {
            ret = 0;
            for(int i = idx; i <= pSum.size() - k; i++)
            {
                ret = max(ret, max(pSum[i] - pSum[idx - 1], find(i + 1, k - 1)));
            }
        }
        return ret;
    }

    int splitArray(vector<int>& nums, int k) {
        pSum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            pSum.push_back(pSum[i - 1] + nums[i]);
        }
        if(k == 1) return pSum[nums.size() - 1];
        memset(cache, -1, sizeof(cache));
        return find(0, k);
    }
};
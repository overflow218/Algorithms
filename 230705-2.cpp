class Solution {
public:
    int cache[2000] = {0};
    int count[2000] = {0};
    int find(int idx, vector<int>& nums)
    {
        int &ret = cache[idx];
        if(ret != 0) return ret;
        ret = 1;
        for(int i = idx + 1; i < nums.size(); i++)
        {
            if(nums[idx] < nums[i]) ret = max(ret, 1 + find(i, nums));
        }
        return ret;
    }

    int getCount(int idx, vector<int>& nums)
    {
        if(cache[idx] == 1) return 1;
        int &ret = count[idx];
        if(ret != 0) return ret;
        
        for(int i = idx + 1; i < nums.size(); i++)
        {
            if(nums[idx] < nums[i] && (cache[idx] == cache[i] + 1)) ret += getCount(i, nums);
        }
        return ret;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int lis = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            lis = max(lis, find(i, nums));
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(cache[i] == lis) cnt += getCount(i, nums);
        }
        return cnt;
    }
};
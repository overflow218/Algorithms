class Solution {
public:
    int count[1000001] = {0};
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                count[abs(nums[i] - nums[j])]++;
            }
        }
        int cnt = 0;
        for(int i = 0; i <= 1000000; i++)
        {
            if(cnt + count[i] >= k) return i;
            cnt += count[i];
        }
        return -1;
    }
};
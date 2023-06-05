class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(const int num: nums)
        {
            if(num == 0) return 0;
            if(num < 0) ans = -ans;
        }
        return ans;
    }
};
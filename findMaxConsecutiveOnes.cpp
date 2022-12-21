class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, con = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i])
            {
                if(nums[i -1]) {
                    con++;
                } else 
                {
                    con = 1;
                }
            } else 
            {
                ans = max(ans, con);
                con = 0;            
            }
        }
        ans = max(ans, con);
        return ans;
    }
};
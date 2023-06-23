class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tmp = -20000; 
        int cnt = 0, idx = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(tmp == nums[i] && cnt < 2)
            {
                cnt++;
                nums[idx++] = nums[i];
            }
            if(tmp != nums[i])
            {
                tmp = nums[i];
                cnt = 1;
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, tmp = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(tmp == nums[i]) cnt++;
            if(tmp != nums[i]) cnt--;
            if(cnt == 0)
            {
                tmp = nums[i];
                cnt = 1;
            }
        }
        return tmp;
    }
};
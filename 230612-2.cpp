class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        if(nums.size() == 0)
        {
            ans.push_back({lower, upper});
            return ans;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0 && lower < nums[0]) ans.push_back({lower, nums[0]- 1});
            if(i == nums.size() - 1 && nums.back() < upper) ans.push_back({nums.back() + 1, upper});
            if(i + 1 < nums.size() && nums[i] + 1 < nums[i + 1]) ans.push_back({nums[i] + 1, nums[i + 1] - 1});
        }
        return ans;
    }
};
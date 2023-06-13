class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int freq, val;
        for(int i = 0; i < nums.size(); i += 2)
        {
            freq = nums[i]; val = nums[i + 1];
            for(int j = 0; j < freq; j++)
            {
                ans.push_back(val);
            } 
        }
        return ans;
    }
};
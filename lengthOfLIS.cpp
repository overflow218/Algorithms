#include <algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int> vec;

       for(int i = 0; i < nums.size(); i++)
       {
           if(vec.empty() || vec.back() < nums[i])
           {
               vec.push_back(nums[i]);
           } else 
           {
               int idx = lower_bound(vec.begin(), vec.end(), nums[i]) - vec.begin();
               vec[idx] = nums[i];
           }
       } 
       return vec.size();
    }
};
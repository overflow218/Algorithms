#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int idx = 0;
        vector<string> ans;
        while(idx < nums.size())
        {
            int from = nums[idx];
            int to = nums[idx];
            idx++;
            while(idx < nums.size() && nums[idx - 1] + 1 == nums[idx])
            {
                to = nums[idx];
                idx++;
            }
            string tmp = from == to ? to_string(from) : to_string(from) + "->" + to_string(to);
            ans.push_back(tmp);
        }
        return ans;
    }
};
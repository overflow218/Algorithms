// leetcode 1441번
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int idx = 0;
        vector<string> ans;
        for(int i = 1; i <= n; i++)
        {
            if(i > target.back()) break;
            ans.push_back("Push");
            if(target[idx] == i)
            {
                idx++;
                continue;
            }
            ans.push_back("Pop");
        }
        return ans;
    }
};

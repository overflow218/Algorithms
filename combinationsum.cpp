class Solution {
public:
    vector<vector<int>> ans;
    void check(int idx, int sum, vector<int> &candidates, vector<int> &chosen)
    {
        if(sum < 0) return;
        if(sum == 0)
        {
            ans.push_back(chosen);
            return;
        }

        for(int i = 0; i <= idx; i++)
        {
            chosen.push_back(candidates[i]);
            check(i, sum - candidates[i], candidates, chosen);
            chosen.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> chosen;
        for(int i = 0; i < candidates.size(); i++)
        {
            chosen.push_back(candidates[i]);
            check(i, target - candidates[i], candidates, chosen);
            chosen.pop_back();
        }
        return ans;
    }
};
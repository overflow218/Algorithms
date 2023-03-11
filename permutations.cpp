class Solution {
public:
    vector<vector<int>> ans;

    void permutation(vector<bool> &isVisited, vector<int>& nums, vector<int> &chosen)
    {
        if(chosen.size() == isVisited.size())
        {
            ans.push_back(chosen);
            return;
        }

        for(int i = 0; i < isVisited.size(); i++)
        {
            if(!isVisited[i])
            {
                isVisited[i] = true;
                chosen.push_back(nums[i]);
                permutation(isVisited, nums, chosen);
                chosen.pop_back();
                isVisited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isVisited(n, false);
        vector<int> chosen;
        permutation(isVisited, nums, chosen);
        return ans;
    }
};
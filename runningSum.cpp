class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer = {nums[0]};
        for(int i = 1; i < nums.size(); i++)
        {
            answer.push_back(answer.back() + nums[i]);
        }
        return answer;
    }
};
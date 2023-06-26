class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> vec;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            bool isDone = false;
            for(int j = 1; j < n; j++)
            {
                if(nums[i] < nums[(i + j) % n])
                {
                    isDone = true;
                    vec.push_back(nums[(i + j) % n]);
                    break;
                }
            }
            if(!isDone) vec.push_back(-1);
        }
        return vec;
    }
};
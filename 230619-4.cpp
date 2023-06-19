#include <algorithm>
class Solution {
public:
    vector<vector<int>> vec = vector<vector<int>>(301);
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;
        if(arr.size() == 0) return 0;
        const int MOD = 1000000007;
        for(int i = 0; i < arr.size(); i++)
        {
            vec[arr[i]].push_back(i);
        }
        
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = i + 1; j < arr.size(); j++)
            {
                int sum = arr[i] + arr[j];
                if(sum > target) continue;
                int needed = target - sum;
                int idx = upper_bound(vec[needed].begin(), vec[needed].end(), j) - vec[needed].begin();
                // printf("idx: %d, size; %d\n", idx, vec[needed].size());
                ans = (ans + vec[needed].size() - idx) % MOD;
            }
        }
        return ans;
    }
};
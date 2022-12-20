#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        set<vector<int>> s;
        int arr[200010] = {0};
        const int pad = 100000;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            arr[nums[i] + pad]++;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                int needed = -(nums[i] + nums[j]);
                if(needed > pad || needed < -pad || needed < nums[j]) continue;
                arr[pad + nums[i]]--;
                arr[pad + nums[j]]--;
                if(arr[pad + needed] > 0)
                {
                    vector<int> vec = {nums[i], nums[j], needed};
                    s.insert(vec);
                }
                arr[pad + nums[i]]++;
                arr[pad + nums[j]]++;
            }
        }
        answer = vector<vector<int>>(s.begin(), s.end());
        return answer;
    }
};
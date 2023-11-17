/*
leetcode 1877번. 
일단 드는 생각은 정렬때린다음에 
제일 작은거 + 제일 큰거 쌍으로 만들면 안되는가라는 생각 ㅋㅋ
그리디로 될거같은데 증명은 모르겠당
*/
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n / 2; i++)
        {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }        
        return ans;
    }
};

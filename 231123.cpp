/*
leetcode 1630번

일단 arithmetic 은 등차수열인지 물어보는거네
대상 수열도 500개가 안되고 쿼리도 500개가 안됨. 

500번마다 매번 정렬해서 등차인지 확인한다고 하면
O(n) * O(nlogn) => O(n^2logn) 이네 
25만 * ... 이니까 그냥 실행해도 문제 없어보이긴하네
다른 좋은 방법이 있을까?
만약에 시간초과나면 DP를 고민해보든 뭐 그래야할둡
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    bool isArithmetic(vector<int> &nums)
    {
        int d = nums[1] - nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] - nums[i - 1] != d) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;

        for(int i = 0; i < l.size(); i++)
        {
            vector<int> tmp = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(tmp.begin(), tmp.end());
            ans.push_back(isArithmetic(tmp));
        }
        return ans;
    }
};

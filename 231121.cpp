/*
leetcode 1814번
일단 10만개라서 걍 O(n^2)으로 돌리기는 어려워보이넹
이런게 가끔 식만 잘 쪼물닥거려도 쉽게 풀리는 경우가 있음. 
보면 nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
이거 구하면 됨. 
저거 차이가 얼마가 나올지는 모르겠으나 각각 개수 카운팅해준다음에
nC2 해서 구해주면 되네. 10만C2하면 오버플로우 나올수도 있으니까 
long long으로 바꿔서 해주면 끝
*/

#include <map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    const long long MOD = 1000000007;
    map<int, int> counter;

    int reverse(int x){
        string tmp = to_string(x);
        std::reverse(tmp.begin(), tmp.end());
        int ho = stoi(tmp);
        return ho;
    }

    int countNicePairs(vector<int>& nums) {
        long long ans = 0;
        for(auto &n: nums)
        {
            int diff = n - reverse(n);
            if(counter.find(diff) == counter.end()) counter[diff] = 0;
            counter[diff]++;
        }    

        for(auto it: counter)
        {
            long long cnt = it.second;
            if(cnt >= 2) ans = (ans + cnt * (cnt - 1ll) / 2ll) % MOD;
        }
        return ans;
    }
};

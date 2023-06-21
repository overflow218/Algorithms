/*
당근 뭐로 맞추든 맞추는건 문제가 아님. 
근데 비용을 최소로 해야한다는게 문제이지. 범위는 최소 ~ 최대 사이에 있는 
어떤 값으로 맞추는게 비용이 최소가 될거임. 저 사이에서 이분탐색을 적용하면 좋을 것 같긴한데
문제는 이분 탐색을 했을때 어느쪽으로 가야할지가 명확하지 않다는게 문제이지...
이거 분포가 극값이 있는 그런 분포일거 같은데 그런 경우라면 3분 탐색을 활용할 수 있단말이지
1 3 5 2
2 3 1 14
*/
class Solution {
public:
    long long getCost(int target, vector<int>& nums, vector<int>& cost)
    {
        long long cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cnt += (long long)abs(nums[i] - target) * (long long)cost[i];
        }
        return cnt;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int mini = 2000000, big = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            mini = min(nums[i], mini);
            big = max(nums[i], big);
        }
        int s = mini, e = big;
        while(e - s > 2)
        {
            // printf("s: %d, e: %d\n", s, e);
            int p = (2 * s + e) / 3;
            int q = (s + 2 * e) / 3;
            long long pCost = getCost(p, nums, cost);
            long long qCost = getCost(q, nums, cost);
            if(pCost < qCost)
            {
                e = q;
            } else 
            {
                s = p;
            }            
        }
        long long ans = getCost(s, nums, cost);
        ans = min(ans, getCost(s + 1, nums, cost));
        ans = min(ans, getCost(s + 2, nums, cost));
        // printf("afeter s: %d, e: %d\n", s, e);
        return ans;
    }
};
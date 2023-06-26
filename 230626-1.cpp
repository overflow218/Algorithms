#include <set>
class Solution {
public:
    set<pair<int, int>> s;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int left = 0, right = costs.size() - 1;
        bool isDone[100000] = {false};
        for(int i = 0; i < candidates; i++)
        {
            s.insert(make_pair(costs[i], i));
            s.insert(make_pair(costs[costs.size() - 1 - i], costs.size() - 1 - i));
        }
        left = candidates - 1;
        right = costs.size() - candidates;

        int cnt = 0;
        while(cnt < k)
        {
            pair<int, int> tmp = *s.begin();
            s.erase(s.begin());
            int idx = tmp.second;
            if(isDone[idx]) continue;
            ans += tmp.first;
            isDone[idx] = true;
            cnt++;
            if(idx <= left && left + 1 < costs.size())
            {
                left++;
                s.insert(make_pair(costs[left], left));
            }
            if(idx >= right && right - 1 >= 0)
            {
                right--;
                s.insert(make_pair(costs[right], right));
            }
        }
        return ans;
    }
};
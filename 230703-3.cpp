#include <algorithm>
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int s = 0, e = citations.back();
        int ans = 0;
        while(s <= e)
        {
            int mid = (s + e) / 2;
            int idx = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
            int cnt = citations.size() - idx;
            if(cnt >= mid)
            {
                // printf("mid: %d possible\n", mid);
                ans = max(ans, mid);
                s = mid + 1;
            } else 
            {
                // printf("mid: %d impossible\n", mid);
                e = mid - 1;
            }
        }
        return ans;
    }
};
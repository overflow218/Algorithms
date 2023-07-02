#include <algorithm>
class Solution {
public:
    bool isDone[20] = {false};
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int k = requests.size();
        int limit = 1 << k;
        int ans = 0;
        for(int i = 0; i < limit; i++)
        {
            int reqCnt = 0;
            int degree[20] = {0};
            bool isPossible = true;
            for(int j = 0; j < k; j++)
            {
                if(i & (1 << j))
                {
                    reqCnt++;
                    degree[requests[j][0]]--;
                    degree[requests[j][1]]++;
                }
            }

            for(int j = 0; j < n; j++)
            {
                if(degree[j] != 0) isPossible = false;
            }
            if(isPossible) ans = max(ans, reqCnt);
        }
        return ans;
    }
};
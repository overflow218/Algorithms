#include <queue>

class Solution {
public:
    queue<pair<int, int>> q;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> henchmen(n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == headID) continue;
            henchmen[manager[i]].push_back(i);
        }
        
        q.push(make_pair(headID, 0));

        while(!q.empty())
        {
            int curIdx = q.front().first, cost = q.front().second;
            q.pop();
            ans = max(ans, cost);
            for(int i = 0; i < henchmen[curIdx].size(); i++)
            {
                q.push(make_pair(henchmen[curIdx][i], cost + informTime[curIdx]));
            }
        }
        return ans;        
    }
};
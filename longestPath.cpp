#include <queue>
class Solution {
public:
    int ans = 0;
    int find(int idx, vector<vector<int>> &edge, string &s)
    {
        priority_queue<int> pq;
        for(int i = 0; i < edge[idx].size(); i++)
        {
            int siblingIdx = edge[idx][i];
            int tmp = find(siblingIdx, edge, s);
            if(s[siblingIdx] != s[idx])
            {
                pq.push(tmp);
            }
        }
        int first = 0, second = 0;
        if(!pq.empty())
        {
            first = pq.top();
            pq.pop();
        }
        if(!pq.empty())
        {
            second = pq.top();
            pq.pop();
        }

        ans = max(first + second + 1, ans);
        return first + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> edge(n);
        for(int i = 1; i < n; i++)
        {
            edge[parent[i]].push_back(i);
        }
        find(0, edge, s);
        return ans;
    }
};
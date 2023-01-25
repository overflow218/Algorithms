#include <queue>
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        const int INF = 1000000;
        vector<int> dist1 (n, INF);
        vector<int> dist2 (n, INF);
        queue<pair<int, int>> q;

        q.push(make_pair(node1, 0));
        while(!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            int cur = tmp.first, distance = tmp.second;
            if(cur == -1 || dist1[cur] != INF) continue;
            dist1[cur] = distance;
            q.push(make_pair(edges[cur], distance + 1));
        }

        q.push(make_pair(node2, 0));
        while(!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            int cur = tmp.first, distance = tmp.second;
            if(cur == -1 || dist2[cur] != INF) continue;
            dist2[cur] = distance;
            q.push(make_pair(edges[cur], distance + 1));
        }

        int ans = INF, idx = -1;
        for(int i = 0; i < n; i++)
        {
            if(ans > max(dist1[i], dist2[i]))
            {
                ans = max(dist1[i], dist2[i]);
                idx = i;
            }
        }
        return idx;
    }
};
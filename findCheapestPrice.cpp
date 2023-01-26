#include <queue>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> path(n);
        // (현재 위치, 이동 거리)
        queue<pair<int, int>> q;
        const int INF = 987654321;
        int ans = INF;
        vector<int> dist(n, INF);

        for(auto &flight: flights)
        {
            path[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }

        q.push(make_pair(src, 0));
        for(int i = 0; i <= k + 1; i++)
        {
            if(q.empty()) break;
            int len = q.size();
            for(int j = 0; j < len; j++)
            {
                pair<int, int> tmp = q.front();
                int curPos = tmp.first, curDist = tmp.second;
                // printf("pos:%d, dist: %d\n", curPos, curDist);
                q.pop();
                if(dist[curPos] <= curDist) continue;
                dist[curPos] = curDist;
                if(curPos == dst)
                {
                    ans = min(ans, curDist);
                }
                for(auto &edge: path[curPos])
                {
                    q.push(make_pair(edge.first, curDist + edge.second ));
                }
            }
        }
        return ans == INF ? -1 : ans;
    }
};
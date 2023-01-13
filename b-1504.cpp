#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 200000010;
priority_queue<pair<int, int>> pq;

void dijkstra(vector<vector<pair<int, int>>> &edge, vector<int> &dist)
{
    while(!pq.empty())
    {
        int d = -pq.top().first, idx = pq.top().second;
        pq.pop();
        if(d > dist[idx]) continue;;
        dist[idx] = d;
        for(int i = 0; i < edge[idx].size(); i++)
        {
            int next = edge[idx][i].first, cost = edge[idx][i].second;
            if(dist[next] > dist[idx] + cost)
            {
                dist[next] = dist[idx] + cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main()
{
    int n, e, a, b, c, X, Y;
    scanf("%d %d", &n, &e);
    vector<vector<pair<int, int>>> edge(n + 1);
    vector<int> dist1(n + 1, INF);
    vector<int> distX(n + 1, INF);
    vector<int> distY(n + 1, INF);

    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    scanf("%d %d", &X, &Y);
    
    pq.push(make_pair(0, 1));
    dijkstra(edge, dist1);

    pq.push(make_pair(0, X));
    dijkstra(edge, distX);

    pq.push(make_pair(0, Y));
    dijkstra(edge, distY);

    int ans = min(dist1[X] + distX[Y] + distY[n], dist1[Y] + distY[X] + distX[n]);
    ans = ans >= INF ? -1 : ans;
    printf("%d\n", ans);
    return 0;
}
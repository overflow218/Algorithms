#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
const int INF = 300000;
void dijkstra(vector<vector<pair<int, int>>> &edge, vector<int> & dist)
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
            if(dist[next] > d + cost)
            {
                dist[next] = d + cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}
int main()
{
    int v, e, k, a, b, c;
    scanf("%d %d %d", &v, &e, &k);

    // edge[i] = {(i와 연결된 노드, 거리)이 담긴 벡터}
    vector<vector<pair<int, int>>> edge(v + 1);
    vector<int> dist(v + 1, INF);
    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(make_pair(b, c));
    }

    pq.push(make_pair(0, k));
    dijkstra(edge, dist);

    for(int i = 1; i <= v; i++)
    {
        if(i == k)
        {
            printf("0\n");
        } else
        {
            if(dist[i] >= INF)
            {
                printf("INF\n");
            } else 
            {
                printf("%d\n", dist[i]);
            }
        }
    }
    return 0;
}
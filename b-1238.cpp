#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int>& dist)
{
    while(!pq.empty())
    {
        int d = -pq.top().first, idx = pq.top().second;
        pq.pop();
        if(d > dist[idx]) continue;
        dist[idx] = d;
        for(int i = 0; i < graph[idx].size(); i++)
        {
            int next = graph[idx][i].first, cost = graph[idx][i].second;
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
    int n, m, x, a, b, c;
    scanf("%d %d %d", &n, &m , &x);
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<pair<int, int>>> reverse(n + 1);
    vector<int> dist(n + 1, 987654321);
    vector<int> reverse_dist(n + 1, 987654321);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        reverse[b].push_back(make_pair(a, c));
    }

    pq.push(make_pair(0, x));
    dijkstra(graph, dist);

    pq.push(make_pair(0, x));
    dijkstra(reverse, reverse_dist);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i] + reverse_dist[i]);
    }
    printf("%d\n", ans);

    return 0;
}
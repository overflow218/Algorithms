#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m, a, b, c, start, end;
    scanf("%d %d", &n, &m);
    // (도착 노드, 거리)
    vector<pair<int, int>> edge[n + 1];
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(make_pair(b, c));
    }

    scanf("%d %d", &start, &end);

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    vector<int> dist(n + 1, 987654321);
    vector<int> prev(n + 1, 0);

    dist[start] = 0;
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cost = -cur.first;
        int idx = cur.second;
        if(dist[idx] < cost) continue;

        for(int i = 0; i < edge[idx].size(); i++)
        {
            int next = edge[idx][i].first;
            int nCost = edge[idx][i].second;

            if(dist[next] > dist[idx] + nCost)
            {
                dist[next] = dist[idx] + nCost;
                prev[next] = idx;
                pq.push(make_pair( - dist[next], next));
            }
        }
    }

    vector<int> route;
    int current = end;
    while(current)
    {
        route.push_back(current);
        current = prev[current];
    }

    printf("%d\n", dist[end]);
    printf("%d\n", route.size());
    for(int i = (int)route.size() - 1; i >= 0; i--)
    {
        printf("%d ", route[i]);
    }
    printf("\n");
    return 0;
}
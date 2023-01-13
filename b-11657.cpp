#include <iostream>
#include <vector>
using namespace std;

const long long INF = 30000000000;

bool hasNegativeCycle(vector<vector<int>>& edge, vector<long long> &dist)
{
    int v = dist.size() - 1;
    for(int t = 1; t <= v; t++)
    {
        for(int i = 0; i < edge.size(); i++)
        {
            int from = edge[i][0], to = edge[i][1], cost = edge[i][2];
            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + ((long long)cost))
            {
                if(t == v) return true;
                dist[to] = dist[from] + ((long long)cost);
            }
        }
    }
    return false;
}

int main()
{
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    vector<vector<int>> edge;
    vector<long long> dist(n + 1, INF);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back({a, b, c});
    }
    dist[1] = 0;
    if(hasNegativeCycle(edge, dist))
    {
        printf("-1\n");
    } else 
    {
        for (int i = 2; i <= n; i++)
        {
            printf("%lld\n", dist[i] == INF ? -1 : dist[i]);
        }
    }
    return 0;
}
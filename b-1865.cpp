#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

// negative cycle 있으면 true, 없으면 false
bool hasNegativeCycle(vector<vector<int>> &edge, vector<int>& dist)
{
    int v = dist.size() -1;
    for(int c = 1; c <= v; c++)
    {
        for(int i = 0; i < edge.size(); i++)
        {
            int from = edge[i][0], to = edge[i][1], cost = edge[i][2];
            if(dist[to] > dist[from] + cost)
            {
                if(c == v) return true;
                dist[to] = dist[from] + cost;
            }
        }
    }
    return false;
}
int main()
{
    int tc, n, m, w, s, e, t;
    scanf("%d", &tc);
    for(int h = 0; h < tc; h++)
    {
        scanf("%d %d %d", &n, &m, &w);
        // 여기에 일반 길과 웜홀을 함께 포함해서 저장.
        vector<vector<int>> edge;
        vector<int> dist(n + 1, INF);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &s, &e, &t);
            // 길은 양방향
            edge.push_back({s, e, t});
            edge.push_back({e, s, t});
        }

        for(int i = 0; i < w; i++)
        {
            scanf("%d %d %d", &s, &e, &t);
            // 웜홀은 단방향
            edge.push_back({ s, e, -t });
        }

        dist[1] = 0;
        if(hasNegativeCycle(edge, dist))
        {
            printf("YES\n");
        } else 
        {
            printf("NO\n");
        }
    }
}
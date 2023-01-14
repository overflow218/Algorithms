#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// (거리, 노드)
priority_queue<pair<int, int>> pq;
int main()
{
    int v, e, a, b, c;
    scanf("%d %d", &v, &e);
    vector<bool> isVisited(v + 1, false);
    vector<vector<pair<int, int>>> edge(v + 1);

    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

    pq.push(make_pair(0, 1));
    int ans = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first,  node = pq.top().second;
        pq.pop();
        if(isVisited[node]) continue;
        isVisited[node] = true;
        ans += cost;

        for(int i = 0; i < edge[node].size(); i++)
        {
            int next = edge[node][i].first, cost = edge[node][i].second;
            if(isVisited[next]) continue;
            pq.push(make_pair(-cost, next));
        }
    }

    printf("%d\n", ans);
    return 0;
}
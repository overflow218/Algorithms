#include <string>
#include <vector>
#include <queue>
using namespace std;

const int INF = 200000000;
priority_queue<pair<int, int>> pq;

vector<int> distS = vector<int>(201, INF);
vector<int> distA = vector<int>(201, INF);
vector<int> distB = vector<int>(201, INF);

vector<vector<pair<int, int>>> edges = vector<vector<pair<int, int>>>(201);

void dijkstra(int start, vector<int> &distVec)
{
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int dist = -pq.top().first, idx = pq.top().second;
        pq.pop();
        if (distVec[idx] < dist)
            continue;
        distVec[idx] = dist;
        for (int i = 0; i < edges[idx].size(); i++)
        {
            int next = edges[idx][i].first, cost = dist + edges[idx][i].second;
            pq.push(make_pair(-cost, next));
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    for (int i = 0; i < fares.size(); i++)
    {
        int a = fares[i][0], b = fares[i][1], c = fares[i][2];
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }
    // start 기준으로 다익스트라 한번
    dijkstra(s, distS);
    // a 기준으로 한번
    dijkstra(a, distA);
    // b 기준으로 한번 더 돌린다
    dijkstra(b, distB);

    // 경유 안하고 그냥 가는 경우
    int answer = distS[a] + distS[b];
    // 경우하는 경우해서 더 나은 경우가 있는지 체크
    for (int i = 1; i <= n; i++)
    {
        // i 노드가 경유점이 되는거임
        int tmp = distS[i] + distA[i] + distB[i];
        answer = min(answer, tmp);
    }

    return answer;
}
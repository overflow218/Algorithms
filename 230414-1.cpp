#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<int> dist(100001, -1);
vector<vector<int>> edges = vector<vector<int>> (100001);
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(auto &road: roads)
    {
        int a = road[0], b = road[1];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    pq.push(make_pair(0, destination));
    while(!pq.empty())
    {
        int d = -pq.top().first, idx = pq.top().second;
        pq.pop();
        if(dist[idx] != -1 && dist[idx] < d) continue;
        dist[idx] = d;
        
        for(int i = 0; i < edges[idx].size(); i++)
        {
            int next = edges[idx][i];
            if(dist[next] == -1 || d + 1 < dist[next])
            {
                pq.push(make_pair(-d -1, next));
            }
        }
    }
    
    for(const auto & source: sources)
    {
        answer.push_back(dist[source]);
    }
    
    return answer;
}
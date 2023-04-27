#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool lightOn[100001] = {false};
int count[100001] = {0};
queue<int> q;

vector<vector<int>> edges = vector<vector<int>>(100001);
int solution(int n, vector<vector<int>> lighthouse) {
    for(const auto & light: lighthouse)
    {
        count[light[0]]++;
        count[light[1]]++;
        edges[light[0]].push_back(light[1]);
        edges[light[1]].push_back(light[0]);
    }
    for(int i = 1; i <= n; i++)
    {
        if(count[i] == 1) q.push(i);
    }
    
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        for(int i = 0; i < edges[a].size(); i++)
        {
            int b = edges[a][i];
            if(count[b] == 0) continue;
            count[b]--;
            count[a]--;
            if(!lightOn[a]) lightOn[b] = true;
            if(count[b] == 1)
            {
                q.push(b);
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(lightOn[i]) answer++;
    }
    return answer;
}
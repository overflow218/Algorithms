#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
bool isVisited[20001] = {false};
vector<vector<int>> connected = vector<vector<int>>(20001);
int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        connected[edge[i][0]].push_back(edge[i][1]);
        connected[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    while (!q.empty())
    {
        int limit = q.size();
        int cnt = 0;
        for (int i = 0; i < limit; i++)
        {
            int x = q.front();
            q.pop();
            if (isVisited[x])
                continue;
            cnt++;
            isVisited[x] = true;
            for (int j = 0; j < connected[x].size(); j++)
            {
                q.push(connected[x][j]);
            }
        }
        if (cnt != 0)
            answer = cnt;
    }
    return answer;
}
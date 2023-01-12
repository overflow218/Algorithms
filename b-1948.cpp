#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int roadCnt = 0;
bool isVisited[10001] = {false};

int findTime(int idx, int dest, vector<vector<pair<int, int>>> &edge, vector<int> &cost)
{
    if(idx == dest) return 0;
    int & ret = cost[idx];
    if(ret != 0) return ret;

    ret = -987654321;
    int tmpCnt = 0;
    for(int i = 0; i < edge[idx].size(); i++)
    {
        ret = max(ret, findTime(edge[idx][i].first, dest, edge, cost) + edge[idx][i].second);
    }
    return ret;
}

void findRoad(int idx, int dest, vector<vector<pair<int, int>>> &edge, vector<int> &cost)
{
    if(idx == dest || isVisited[idx]) return;
    isVisited[idx] = true;

    for(int i = 0; i < edge[idx].size(); i++)
    {
        if(cost[idx] == findTime(edge[idx][i].first, dest, edge, cost) + edge[idx][i].second)
        {
            roadCnt++;
            findRoad(edge[idx][i].first, dest, edge, cost);
        } 
    }
}

int main()
{
    int n, m, from, to, c;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> edge(n + 1);
    vector<int> cost(n + 1, 0);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &from, &to, &c);
        // (다음 노드, 가는데 걸리는 시간)
        edge[from].push_back(make_pair(to, c));
    }
    scanf("%d %d", &from, &to);

    // 1. find max time
    int time = findTime(from, to, edge, cost);
    printf("%d\n", time);
    // 2. find road count
    findRoad(from, to, edge, cost);
    printf("%d\n", roadCnt);
    return 0;
}
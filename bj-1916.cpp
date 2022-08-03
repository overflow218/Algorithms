#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int dist[1000][1000] = {0}, n, m;
int ans[1000][1000] = {-1};
bool isVisited[1000][1000] = {false};
map<int, vector<int> > city;

int find(int from , int to)
{
    if(from == to || ans[from][to])
    {
        return 0;
    }

    int ans = 987654321;
    isVisited[from][to] = true;
    isVisited[to][from] = true;
    
    for(int i = 0; i < city[from].size(); i++)
    {
        int next = city[from][i];
        if(!isVisited[next][to])
        {
            ans = min(ans, dist[from][next] + find(next, to));
        }
    }
    return ans;
}

int main()
{
    int from, to, d;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &from, &to, &d);
        dist[from][to] = d;
        city[from].push_back(to);
    }

    scanf("%d %d", &from, &to);
    printf("%d\n", find(from, to));

    for(int i = 0; i < n; i++)
    {
        printf("%d", ans[0][i]);
    }

    return 0;
}
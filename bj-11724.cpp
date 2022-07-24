#include <iostream>
#include <cstdio>
using namespace std;

bool isVisited[1001] = {false};
bool isConnected[1001][1001] = {false};
int n, m, u, v, cnt = 0;   

void go(int x)
{
    if(isVisited[x]) return;
    isVisited[x] = true;
    for(int i = 1; i <= n; i++)
    {
        if(isConnected[x][i])
        {
            go(i);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        isConnected[u][v] = true;
        isConnected[v][u] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!isVisited[i])
        {
            go(i);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}
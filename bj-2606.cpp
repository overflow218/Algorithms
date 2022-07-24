#include<cstdio>
using namespace std;

bool isConnected[101][101] = {false};
bool isVisited[101] = {false};
int n, m, a, b, cnt = -1;
void go(int x)
{
    if(isVisited[x]) return;
    isVisited[x] = true;
    cnt++;
    for(int i = 1; i <= n; i++)
    {
        if(isConnected[x][i]) go(i);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        isConnected[a][b] = true;
        isConnected[b][a] = true;
    }
    go(1);
    printf("%d\n", cnt);
}
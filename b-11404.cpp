#include <iostream>
using namespace std;

int cost[101][101];
const int INF = 987654321;
int main()
{
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    // initialize
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cost[i][j] = i == j ? 0 :INF;
        }
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        cost[a][b] = min(c, cost[a][b]);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int from = 1; from <= n; from++)
        {
            for(int to = 1; to <= n; to++)
            {
                cost[from][to] = min(cost[from][to], cost[from][i] + cost[i][to]);
            }
        }
    }

    // print answer
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ", cost[i][j] == INF ? 0 : cost[i][j]);
        }
        printf("\n");
    }
    return 0;
}
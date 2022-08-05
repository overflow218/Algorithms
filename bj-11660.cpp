#include <iostream>
#include <cstdio>
using namespace std;

int ans[1025][1025] = {0};

int main()
{
    int n, m, x1, x2, y1, y2;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &ans[i][j]);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans[i][j] += ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
        }
    }


    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", ans[x2][y2] - ans[x1 - 1][y2] - ans[x2][y1 - 1] + ans[x1 - 1][y1 - 1]);
    }

    return 0;
}
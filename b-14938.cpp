#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];

int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    vector<int> item(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &item[i]);
    }

    int a, b, w;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            arr[i][j] = i == j ? 0 : 987654321;
        }
    }

    for(int i = 0; i < r; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        arr[a][b] = w;
        arr[b][a] = w;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int from = 1; from <= n; from++)
        {
            for(int to = 1; to <= n; to++)
            {
                if(arr[from][to] > arr[from][i] + arr[i][to])
                {
                    arr[from][to] = arr[from][i] + arr[i][to];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(arr[i][j] <= m)
            {
                cnt += item[j];
            }
        }
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}
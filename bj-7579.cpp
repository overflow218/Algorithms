#include <iostream>
using namespace std;

int memory[100], cost[100], cache[100][10001] = {0};
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> memory[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    cache[0][cost[0]] = memory[0];
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= 10000; j++)
        {
            cache[i][j] = max(cache[i - 1][j], cache[i][j]);
            if(j + cost[i] <= 10000)
            {
                cache[i][j + cost[i]] = max(cache[i][j + cost[i]], cache[i - 1][j] + memory[i]);
            }
        }
    }

    for(int i = 0; i <= 10000; i++)
    {
        if(cache[n - 1][i] >= m)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
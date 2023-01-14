#include <iostream>
using namespace std;

long long cache[101][10][10] = {0};
int main()
{
    int n;
    const long long MOD = 1000000000;
    scanf("%d", &n);
    if(n < 10)
    {
        printf("0\n");
        return 0;
    }
    cache[10][9][0] = 1ll;

    for(int i = 10; i < n; i++)
    {
        for(int front = 1; front <= 9; front++)
        {
            for(int back = 0; back <= 9; back++)
            {
                if(front != 9)
                {
                    cache[i + 1][front + 1][back] = (cache[i + 1][front + 1][back] + cache[i][front][back]) % MOD;
                    // cache[i + 1][front + 1][back] %= MOD;
                }
                if(front != 1)
                {
                    // cache[i + 1][front - 1][back] += cache[i][front][back];
                    cache[i + 1][front - 1][back] = (cache[i + 1][front - 1][back] + cache[i][front][back]) % MOD;
                }
                if(back != 9)
                {
                    // cache[i + 1][front][back + 1] += cache[i][front][back];
                    cache[i + 1][front][back + 1] = (cache[i + 1][front][back + 1] + cache[i][front][back]) % MOD;
                    // cache[i + 1][front][back + 1] %= MOD;
                }
                if(back != 0)
                {
                    // cache[i + 1][front][back - 1] += cache[i][front][back];
                    cache[i + 1][front][back - 1] = (cache[i + 1][front][back - 1] + cache[i][front][back]) % MOD;
                    // cache[i + 1][front][back - 1] %= MOD;
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int front = 1; front <= 9; front++)
        {
            for(int back = 0; back <= 9; back++)
            {
                ans = (ans + cache[i][front][back]) % MOD;
            }
        }
    }
    // for(int front = 1; front <= 9; front++)
    // {
    //     for(int back = 0; back <= 9; back++)
    //     {
    //         ans = (ans + cache[n][front][back]) % MOD;
    //     }
    // }
    // 5461847755 이게 나와야 맞는건뎅
    printf("%lld\n", ans);
    return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;

int stair[300] = {0};
int dp[2][300] = {0};
int n;

int fun(int idx, int cont)
{
    if(idx >= n) return 0;
    if(dp[cont][idx]) return dp[cont][idx];
    if(cont == 1)
    {
        return dp[cont][idx] = stair[idx] + fun(idx + 2, 0);
    }
    return dp[cont][idx] = max(fun(idx + 2, 0), fun(idx + 1, 1)) + stair[idx];
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &stair[n - 1 - i]);
    }
    printf("%d\n", fun(0, 0));
    return 0;
}
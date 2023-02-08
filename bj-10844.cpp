#include <iostream>
using namespace std;

const int MOD = 1000000000;
int dp[2][10] = {0};
int main()
{
    int n;
    cin >> n;

    for(int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 0)
            {
                dp[i%2][j] = dp[(i - 1) %2][1];
            } else if(j == 9)
            {
                dp[i%2][j] = dp[(i - 1) %2][8];
            } else 
            {
                dp[i%2][j] = (dp[(i - 1) %2][j - 1] + dp[(i - 1) %2][j + 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++)
    {
        ans = (ans + dp[n % 2][i]) % MOD;
    }
    cout << ans <<'\n';
    return 0;
}
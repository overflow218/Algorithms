#include <iostream>
using namespace std;

int main()
{
    int n;
    const long long mod = 1000000007;
    long long ans[1000001] = {1, 2, 7};
    scanf("%d", &n);
    for(int i = 3; i <= n; i++)
    {
        ans[i] = (((3ll * ans[i - 1])%mod + ans[i - 2] - ans[i - 3]) + mod) % mod;
    }
    printf("%lld\n", ans[n]);
    return 0;
}
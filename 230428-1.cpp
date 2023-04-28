#include <iostream>
#include <cstdio>
using namespace std;

const long long MOD = 1000000007ll;
long long mulInvert(long long x, int pow)
{
    if(pow == 0) return 1;
    long long half = mulInvert(x, pow / 2);
    long long ret = (half * half) % MOD;
    if(pow & 1) ret = (ret * x) % MOD;
    return ret;
}

int main()
{
    long long n, k, ans = 1;
    cin >> n >> k;
    for(long long i = 1; i <= k; i++)
    {
        ans = (ans * (n - i + 1)) % MOD;
        ans = (ans * mulInvert(i, MOD - 2)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
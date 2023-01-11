#include <iostream>
using namespace std;

const long long mod = 1000000007;

long long gcd(long long a, long long b)
{
    if(b > a) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

// x ^ n 을 계산
long long square(long long x, long long n)
{
    if(n == 1ll)
    {
        return x;
    } 
    long long half = square(x, n / 2ll);
    if(n % 2ll == 1ll)
    {
        return (x * ((half * half) % mod)) % mod;
    }
    return (half * half) % mod;
}

int main()
{
    long long m, n, s;
    long long ans = 0;
    scanf("%lld", &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%lld %lld", &n, &s);
        long long common = gcd(n, s);
        n /= common;
        s /= common;
        long long tmp = (s * square(n, mod - 2)) % mod;
        ans = (ans + tmp) % mod;
    }

    printf("%lld\n", ans);
    return 0;
}
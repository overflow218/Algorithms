#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1000000007;
vector<long long> multiply(vector<long long> a, vector<long long> b)
{
    return { ((a[0] * b[0]) % mod + (a[1] * b[2]) % mod) % mod, ((a[0] * b[1]) % mod + (a[1] * b[3]) % mod) % mod, ((a[2] * b[0]) % mod + (a[3] * b[2]) % mod) % mod, ((a[2] * b[1]) % mod + (a[3] * b[3]) % mod) % mod};
}

vector<long long> squre(vector<long long> a, long long n)
{
    if(n == 1ll)
    {
        return a;
    } else if(n % 2 == 1)
    {
        vector<long long> half = squre(a, n / 2);
        vector<long long> tmp = multiply(half, half);
        return multiply(a, tmp);
    } else 
    {
        vector<long long> half = squre(a, n / 2);
        return multiply(half, half);
    }
}


int main()
{
    long long n;
    scanf("%lld", &n);
    if(n <= 2ll)
    {
        printf("1\n");
    } else 
    {
        vector<long long> ans = squre({1ll, 1ll, 1ll, 0ll}, n);
        printf("%lld\n", ans[1]);
    }
    return 0;
}
// 1000000000000000000
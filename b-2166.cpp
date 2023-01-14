#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<long long> x(n);
    vector<long long> y(n);

    for(int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    long long ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        ans += x[i] * y[i + 1];
        ans -= x[1 + i] * y[i];
    }
    printf("before: %lld\n", ans);
    ans = abs(ans);
    printf("after: %lld\n", ans);
    ans = ans / 2;

    double ho = ans;
    printf("%.1f\n", ho);
    return 0;
}
// 39999999999.5
// 30000049999.0
/*
5
-100000 100000
-100000 -100000
100000 -100000
100000 99999
99999 100000
*/
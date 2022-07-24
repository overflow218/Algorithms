#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long t, n, m, x, y;
    scanf("%lld", &t);
    for(int h = 0; h < t; h++)
    {
        scanf("%lld %lld %lld %lld", &m, &n, &x, &y);
        long long limit = n * m;
        long long current = x, step = m, ans = -1;
        x = x % m;
        y = y % n;
        while(current <= limit)
        {
            if(current % m == x && current % n == y)
            {
                ans = current;
                break;
            }
            current += step;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
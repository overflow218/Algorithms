#include <iostream>
using namespace std;

// 앞으로는 무조건 이긴다는 보장이 있음!
// x가 10억이라서 100을 곱하면 넘어감. long long으로 쓰자
int main()
{
    long long x, y;
    scanf("%lld %lld", &x, &y);
    int prob = (y * 100l) / x;
    int ans = -1;
    if(prob < 99)
    {
        long long upper = (prob + 1l) * x - 100l * y;
        long long bottom = 99 - prob;
        ans = upper % bottom == 0 ? upper / bottom : upper / bottom + 1;
    }

    printf("%d\n", ans);
    return 0;
}
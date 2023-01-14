#include <iostream>
using namespace std;

int main()
{
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

    long long a1 = y2 - y1;
    long long b1 = x1 - x2;
    long long c1 = -a1 * x1 -b1 * y1;
    long long a2 = y4 - y3;
    long long b2 = x3 - x4;
    long long c2 = -a2 * x3 -b2 * y3;

    long long a3 = a1 - a2;
    long long b3= b1 - b2;
    long long c3 = c1 - c2;
    long long tmp1= a3 * x1 + b3 * y1 + c3;
    long long tmp2= a3 * x2 + b3 * y2 + c3;
    printf("a3: %lld, b3: %lld, c3: %lld, tmp1: %lld, tmp2: %lld\n", a3, b3, c3, tmp1, tmp2);
    /*
    2직선이 일치하거나 평행한 경우를 좀 신경써줘야겠는데
    */
    // 이건 두 직선이 일치하는데 만나는지 아닌지 판단해봐야함.
    if(tmp1 == 0 && tmp2 == 0)
    {
        if((max(x1, x2) >= min(x3, x4) && min(x1, x2) <= min(x3, x4)) || max(x1, x2) >= max(x3, x4) && min(x1, x2) <= max(x3, x4))
        {
            printf("1\n");
        } else 
        {
            printf("0\n");
        }
    } else if(tmp1 * tmp2 <= 0)
    {
        printf("1\n");
    } else 
    {
        printf("0\n");
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long a = 1, b = 1, c;

    for(int i = 3; i <= n; i++)
    {
        c = b;
        b = a + b;
        a = c;
    }
    printf("%lld\n", b);
    return 0;
}
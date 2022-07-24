#include <cstdio>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    long long pado[101] ={0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
    for(int i = 11; i <= 100; i++)
    {
        pado[i] = pado[i - 3] + pado[i - 2];
    }
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", pado[n]);
    }
    return 0;
}
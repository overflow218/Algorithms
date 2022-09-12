#include <iostream>
#include <cstdio>
using namespace std;

const int MOD = 1000000007;
int cache[101] = {0, 1, 2};

int find(int n)
{
    int & ret = cache[n];
    if(ret) return ret;
    return ret = (find(n - 1) + find(n - 2)) % MOD;
}

int main()
{
    int c, n;
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d", &n);
        printf("%d\n", find(n));
    }    
    return 0;
}
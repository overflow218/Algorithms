#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

set<int> s;

int main()
{
    int first = 0, second = 1;
    int const mod = 1000000007;
    long long n;
    scanf("%lld", &n);

    for(long long i = 2; i <= n; i++){
        int tmp = second;
        second = (first + second) % mod;
        first = tmp;

        if(s.find(second) == s.end())
        {
            // printf("%lld번 통과!\n", i);
            s.insert(second);
        } else 
        {
            printf("%lld번째에서 걸림!, first: %d, second:%d\n", i, first, second);
            // break;
        }

    }
    printf("%d\n", second);
    return 0;
}
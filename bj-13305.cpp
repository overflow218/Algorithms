#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<long long> road(n, 0);
    vector<long long> oil(n, 0);
    
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%lld", &road[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &oil[i]);
    }

    long long ans = 0;
    long long oil_price = oil[0];
    long long dist = road[0];
    int cur = 1;
    while(cur < n)
    {
        if(cur == n - 1)
        {
            ans += oil_price * dist;
            break;
        }
        if(oil_price <= oil[cur])
        {
            dist += road[cur++];
        } else 
        {
            
            ans += oil_price * dist;
            oil_price = oil[cur];
            dist = road[cur++];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
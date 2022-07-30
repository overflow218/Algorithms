#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue<pair<long long, long long> > q;

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    q.push(make_pair(a, 1));

    while(!q.empty())
    {
        pair<long long, long long> current = q.front();
        q.pop();
        if(current.first > b) continue;
        if(current.first == b)
        {
            printf("%lld\n", current.second);
            return 0;
        }
        q.push(make_pair(current.first * 2, current.second + 1));
        q.push(make_pair(current.first * 10 + 1, current.second + 1));
    }
    printf("-1\n");
    return 0;
}
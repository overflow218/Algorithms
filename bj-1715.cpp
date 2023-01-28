#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, tmp;
    priority_queue<int> pq;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        pq.push(-tmp);
    }
    long long ans = 0;
    while(pq.size() > 1)
    {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        ans += (long long) (a + b);
        pq.push(-a - b);
    }
    printf("%lld\n", ans);
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main()
{
    int n, k, prev, next;
    scanf("%d %d %d", &n, &k, &prev);
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &next);
        pq.push(next - prev);
        prev = next;
    }

    int ans = 0;
    for(int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }

    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    printf("%d\n", ans);
    return 0;
}
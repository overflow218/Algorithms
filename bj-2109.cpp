#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, p, d;
    scanf("%d", &n);
    vector<int> payment [10001];
    int last_day = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &p, &d);
        payment[d].push_back(p);
        last_day = max(d, last_day);
    }
    
    int ans = 0;
    priority_queue<int> pq;
    while(last_day)
    {  
        for(const int & pay: payment[last_day])
        {
            pq.push(pay);
        }

        if(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        last_day--;
    }

    printf("%d\n", ans);
    return 0;
}
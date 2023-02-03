#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, day, w, last_day = 0;
    scanf("%d", &n);
    vector<int> assignments[1001];
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &day, &w);
        assignments[day].push_back(w);
        last_day = max(last_day, day);
    }
    
    priority_queue<int> pq;
    int ans = 0;
    while(last_day > 0)
    {
        for(const int & score: assignments[last_day])
        {
            pq.push(score);
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
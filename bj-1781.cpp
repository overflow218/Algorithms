#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, due, ramen;
    scanf("%d", &n);
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &due, &ramen);
        vec[i] = make_pair(due, ramen);
    }
    sort(vec.begin(), vec.end());

    int last_day = vec.back().first;
    int ans = 0, idx = n - 1;
    priority_queue<int> pq;
    while(last_day)
    {
        while(idx >= 0 && vec[idx].first == last_day)
        {
            pq.push(vec[idx].second);
            idx--;
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
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int s, e, max_time = 0, ans = 0;
    scanf("%d", &n);
    vector<pair<int, int>> schedule;
    priority_queue<int> room;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &s, &e);
        schedule.push_back(make_pair(s, e));
    }
    sort(schedule.begin(), schedule.end());

    for(const auto& tmp: schedule)
    {
        s = tmp.first, e = tmp.second;
        while(!room.empty() && -room.top() <= s)
        {
            room.pop();
        }

        max_time = max(max_time, e);
        room.push(-e);
        ans = max(ans, (int)room.size());
    }
    printf("%d\n", ans);
    return 0;
}
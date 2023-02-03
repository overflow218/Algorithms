#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, c, m, from, to, box;
    scanf("%d %d %d", &n, &c, &m);
    // n번 마을에서 내릴 짐의 양
    vector<int> deload(n + 1, 0);
    vector<pair<int, int>> order[n + 1];
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &from, &to, &box);
        order[from].push_back(make_pair(to, box));
    }

    int current_load = 0;
    for(int i = 1; i <= n; i++)
    {
        // i번 마을로 오는 박스 내리기
        current_load -= deload[i];
        ans += deload[i];
        sort(order[i].begin(), order[i].end());

        for(const auto& tmp: order[i])
        {
            to = tmp.first, box = tmp.second;
            if(current_load == c) break;
            int load = min(box, c - current_load);
            current_load += load;
            deload[to] += load;
            printf("%d번 마을 -> %d번 마을 : %d개 추가\n", i, to, load);
        }
    }
    printf("%d\n", ans);
    return 0;
}
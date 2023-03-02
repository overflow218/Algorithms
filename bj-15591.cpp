#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 각 노드별로 연결된 곳과 거리 담고 있음.
vector<vector<pair<int, int>>> arr(5001, vector<pair<int, int>>());
queue<pair<int, int>> check;
int main()
{
    int N, Q, p, q, r, k, v;
    cin >> N >> Q;

    for(int i = 0; i < N - 1; i++)
    {
        cin >> p >> q >> r;
        arr[p].push_back(make_pair(q, r));
        arr[q].push_back(make_pair(p, r));
    }

    for(int it = 0; it < Q; it++)
    {
        cin >> k >> v;
        int cnt = 0;
        vector<int> ans(N + 1, 0);
        vector<bool> isVisited(N + 1, false);
        check.push(make_pair(v, 0));

        while(!check.empty())
        {
            int limit = check.size();
            for(int i = 0; i < limit; i++)
            {
                int idx = check.front().first, dist = check.front().second;
                check.pop();
                if(!isVisited[idx])
                {
                    isVisited[idx] = true;
                    ans[idx] = dist;
                    for(const auto &ho: arr[idx])
                    {
                        int next = ho.first, nextDist = ho.second;
                        int tmp = dist == 0 ? nextDist : min(dist, nextDist);
                        check.push(make_pair(next, tmp));
                    }
                }
            }
        }

        for(int i = 1; i <= N; i++)
        {
            if(ans[i] >= k) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
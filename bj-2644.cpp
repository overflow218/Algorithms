#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, from, to, a, b, k;
    cin >> n;
    // parent[i] = i의 부모
    vector<int> parent(n + 1, 0);
    // sibling[i] = i의 자식들
    vector<vector<int>> sibling(n + 1);
    vector<bool> isVisited(n + 1, false);
    cin >> from >> to >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> a >> b;
        parent[b] = a;
        sibling[a].push_back(b);
    }
    int ans = 0;
    queue<int> q;
    q.push(from);

    while(!q.empty())
    {
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            int cur = q.front();
            q.pop();
            if(cur == to)
            {
                cout << ans << '\n';
                return 0;
            }
            if(isVisited[cur]) continue;
            isVisited[cur] = true;

            // 부모 아직 방문안했으면 넣어주기
            if(parent[cur] != 0 && !isVisited[parent[cur]])
            {
                q.push(parent[cur]);
            }

            for(const int & s:sibling[cur])
            {
                if(!isVisited[s])
                {
                    q.push(s);
                }
            }
        }
        ans++;
    }

    // 여기까지 왔으면 친척 아님
    cout << "-1\n";
    return 0;
}
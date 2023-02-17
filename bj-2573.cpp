#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int arr[300][300];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isVisited[300][300] = {false};

int visit(int x, int y)
{
    if(x < 0 || x == n || y < 0 || y == m || isVisited[x][y] || arr[x][y] == 0) return 0;
    int ret = 1;
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        ret += visit(x + dx[i], y + dy[i]);
    }
    return ret;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    queue<pair<int, int>> ice;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] > 0)
            {
                ice.push(make_pair(i, j));
            }
        }
    }

    if(ice.empty())
    {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    while(!ice.empty())
    {
        int limit = ice.size();
        vector<tuple<int, int, int>> next;
        for(int i = 0; i < limit; i++)
        {
            const auto &ho = ice.front();
            ice.pop();
            int x = ho.first, y = ho.second;
            int cnt = arr[x][y];
            for(int j = 0; j < 4; j++)
            {
                int nx = x + dx[j], ny = y + dy[j];
                if(nx < 0 || nx == n || ny < 0 || ny == m) continue;
                if(arr[nx][ny] == 0) cnt--;
            }
            next.push_back(make_tuple(x, y, cnt));
        }

        for(const auto &ho:next)
        {
            int x = get<0>(ho), y = get<1>(ho), cnt = get<2>(ho);
            arr[x][y] = max(0, cnt);
            if(cnt > 0)
            {
                ice.push(make_pair(x, y));
            }
        }

        if(ice.empty()) break;
        ans++;
        // check
        int cnt = visit(ice.front().first, ice.front().second);
        if(cnt != ice.size())
        {
            cout << ans << '\n';
            return 0;
        }
        for(const auto &ho:next)
        {
            int x = get<0>(ho), y = get<1>(ho), cnt = get<2>(ho);
            isVisited[x][y] = false;
        }

    }
    cout << "0\n";
    return 0;
}
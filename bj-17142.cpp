#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lab[50][50] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 987654321;
int n, m, ans = INF, space = 0;
void find(int idx, vector<int> &chosen, vector<pair<int, int>> &virus)
{
    // 바이러스 풀고 시간체크
    if(chosen.size() == m)
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        for(const int &v: chosen)
        {
            int x = virus[v].first, y = virus[v].second;
            q.push(make_pair(x, y));
        }

        int cnt = 0, time = 0;
        while(!q.empty())
        {
            int limit = q.size();
            for(int iter = 0; iter < limit; iter++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x < 0 || x == n || y < 0 || y == n || isVisited[x][y] || lab[x][y] == 1) continue;
                isVisited[x][y] = true;
                if(lab[x][y] == 0) cnt++;
                for(int i = 0; i < 4; i++)
                {
                    q.push(make_pair(x + dx[i], y + dy[i]));
                }
            }
            if(cnt == space)break;
            time++;
        }
        time = cnt == space ? time : INF;
        ans = min(ans, time);
    }else if(idx == virus.size()) 
    {
        return;
    } else 
    {
        for(int i = idx; i < virus.size(); i++)
        {
            chosen.push_back(i);
            find(i + 1, chosen, virus);
            chosen.pop_back();
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> virus;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &lab[i][j]);
            if(lab[i][j] == 2)
            {
                virus.push_back(make_pair(i, j));
            } else if(lab[i][j] == 0) 
            {
                space++;
            }
        }
    }
    vector<int> chosen;
    find(0, chosen, virus);
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}

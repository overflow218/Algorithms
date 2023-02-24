#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[21][21];

// passenger[i] = i번 손님의 출발지 x,y 도착지 x,y
int passenger[500][4];

bool isVisited[21][21];

queue<pair<int, int>> q;
int main()
{
    int n, m, oil;
    cin >> n >> m >> oil;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    q.push(make_pair(x, y));

    for(int i = 2; i <= m + 1; i++)
    {
        cin >> passenger[i][0] >> passenger[i][1] >> passenger[i][2] >> passenger[i][3];
        arr[passenger[i][0]][passenger[i][1]] = i;
    }

    // 탐색시작. 
    int ans = 0;
    while(ans < m)
    {
        int cnt = 0;
        int target = -1;
        memset(isVisited, false, sizeof(isVisited));
        // 탑승할 승객 찾기
        while(!q.empty())
        {
            int limit = q.size();
            vector<pair<int, int>> candidate;
            for(int i = 0; i < limit; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                // 범위 벗어나거나 벽이면 패스
                if(x == 0 || x > n || y == 0 || y > n || arr[x][y] == 1 || isVisited[x][y]) continue;
                isVisited[x][y] = true;
                // 승객 찾음. 
                if(arr[x][y] > 1)
                {
                    candidate.push_back(make_pair(x, y));
                } 
                // 빈칸이라 그냥 이동함. 
                else 
                {
                    for(int j = 0; j < 4; j++)
                    {
                        q.push(make_pair(x + dx[j], y + dy[j]));
                    }
                }
            }

            if(!candidate.empty())
            {
                sort(candidate.begin(), candidate.end());
                target = arr[candidate[0].first][candidate[0].second];
                break;
            }
            cnt++;
        }

        // 기름이 부족하거나 이동이 불가능하면 종료
        if(oil < cnt || target == -1)
        {
            printf("-1\n");
            return 0;
        }
        
        // 기름 줄이기, 큐를 초기화
        oil -= cnt;
        q = queue<pair<int, int>>();
        arr[passenger[target][0]][passenger[target][1]] = 0;
        q.push(make_pair(passenger[target][0], passenger[target][1]));
        int tX = passenger[target][2], tY = passenger[target][3];
        cnt = 0;
        bool find = false;
        memset(isVisited, false, sizeof(isVisited));
        while(!q.empty())
        {
            int limit = q.size();
            for(int i = 0; i < limit; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                // 범위 벗어나거나 벽인 경우 컷
                if(x == 0 || x > n || y == 0 || y > n || arr[x][y] == 1 || isVisited[x][y]) continue;
                isVisited[x][y] = true;
                // 도착지 도착
                if(x == tX && y == tY)
                {
                    find = true;
                } else 
                {
                    for(int j = 0; j < 4; j++)
                    {
                        q.push(make_pair(x + dx[j], y + dy[j]));
                    }
                }
            }
            if(find) break;
            cnt++;
        }

        // 기름 부족하거나 도착지까지 못가는 경우 종료
        if(oil < cnt || !find)
        {
            printf("-1\n");
            return 0;
        }

        // 기름 다시 채워주기
        oil += cnt;
        ans++;

        // 큐를 초기화하고 여기서 다시 시작
        q = queue<pair<int, int>>();
        q.push(make_pair(passenger[target][2], passenger[target][3]));
    }

    cout << oil << '\n';

    return 0;
}
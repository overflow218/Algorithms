#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct horse {
    int x;
    int y;
    int number;
    int direction;
    int position; // 현재 위치에서의 위치. 0이면 제일 아래.
};

// 밑에 있는애가 먼저 와야함
bool cmp(horse a, horse b)
{
    return a.position < b.position;
}

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int opposite(int direction)
{
    if(direction == 0) return 3;
    if(direction == 1) return 2;
    if(direction == 2) return 1;
    if(direction == 3) return 0;

    throw(1);
}

// 판 정보
int arr[13][13];
// 각 칸에 있는 말의 개수
int cnt[13][13];
// i번 말의 정보를 담고 있음.
horse info[13];

int main()
{
    int n, k, x, y, d;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= k; i++)
    {
        cin >> x >> y >> d;
        horse newHorse = {x, y, i, d % 4, 0};
        info[i] = newHorse;
        cnt[x][y] = 1;
    }

    int ans = 0;
    while(ans < 1000)
    {
        ans++;
        for(int i = 1; i <= k; i++)
        {
            int x = info[i].x, y = info[i].y, direction = info[i].direction, position = info[i].position;
            int nx = x + dx[direction], ny = y + dy[direction];

            // 다음칸이 벗어나거나 파란색인경우 방향을 바꿔준다
            if(nx == 0 || nx > n || ny == 0 || ny > n || arr[nx][ny] == 2)
            {
                direction = opposite(direction);
                nx = x + dx[direction], ny = y + dy[direction];
                info[i].direction = direction;
            }

            // 여전히 벗어나거나 파란색이면 얘는 가만히 있음
            if(nx == 0 || nx > n || ny == 0 || ny > n || arr[nx][ny] == 2) continue;

            // 이제 nx, ny칸으로 이동해야하는데 
            vector<horse> candidate;
            for(int j = 1; j <= k; j++)
            {
                if(info[j].x == x && info[j].y == y)
                {
                    candidate.push_back(info[j]);
                }
            }

            sort(candidate.begin(), candidate.end(), cmp);
            int idx;
            for(int j = 0; j < candidate.size(); j++)
            {
                if(candidate[j].position == position)
                {
                    idx = j;
                    break;
                }
            }

            if(arr[nx][ny] == 0)
            {
                // 그냥 가서 순서대로 넣어주면 됨.
                for(int j = idx; j < candidate.size(); j++)
                {
                    cnt[x][y]--;
                    info[candidate[j].number].x = nx;
                    info[candidate[j].number].y = ny;
                    info[candidate[j].number].position = cnt[nx][ny]++;
                }
            } else if(arr[nx][ny] == 1)
            {
                // 순서를 뒤집어서 넣어줘야함.
                int limit = candidate.size();
                for(int j = limit - 1; j >= idx; j--)
                {
                    cnt[x][y]--;
                    info[candidate[j].number].x = nx;
                    info[candidate[j].number].y = ny;
                    info[candidate[j].number].position = cnt[nx][ny]++;
                }
            }

            // 이동후 4칸 이상 쌓이는 경우
            if(cnt[nx][ny] >= 4)
            {
                printf("%d\n", ans);
                return 0;
            }
        }
    }

    printf("-1\n");
    return 0;
}
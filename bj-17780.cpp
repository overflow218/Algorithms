#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int reverse(int direction)
{
    if(direction == 1) return 2;
    if(direction == 2) return 1;
    if(direction == 3) return 4;
    if(direction == 4) return 3;
    return 0;
}

struct Horse{
    int x;
    int y;
    int d;
    int height;
    int id;
};

bool cmp(Horse a, Horse b)
{
    return a.height < b.height;
}

vector<Horse> horses;
int arr[15][15];
// i,j 에 있는 말 개수 
int check[15][15] = {0};
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

    for(int i = 0; i < k; i++)
    {
        cin >> x >> y >> d;
        Horse newHorse = {x, y, d, 0, i};
        horses.push_back(newHorse);
        check[x][y] = 1;
    }

    int cnt = 0;
    while(cnt < 1000)
    {
        cnt++;

        // 1번말부터 차례대로 이동
        for(int i = 0; i < k; i++)
        {
            int x = horses[i].x, y = horses[i].y, d = horses[i].d, h = horses[i].height;
            int nx = x + dx[d], ny = y + dy[d];

            // 제일 아래의 말만 이동 가능
            if(h > 0) continue;
            // 이동하려는 칸이 칸을 벗어나거나 파란색 칸이면 방향 전환
            if(nx == 0 || nx > n || ny == 0 || ny > n || arr[nx][ny] == 2)
            {
                d = reverse(d);
                nx = x + dx[d];
                ny = y + dy[d];
                // 방향 바꾼거 반영해주기
                horses[i].d = d;
            }
            // 방향 바꾸고도 그러면 그냥 이동안함.
            if(nx == 0 || nx > n || ny == 0 || ny > n || arr[nx][ny] == 2) continue;
            
            vector<Horse> candidate;
            // i번째 말이랑 같은칸에 있으면서 i번째 말 위에 있는 애들 다 고름
            for(int j = 0; j < k; j++)
            {
                if(horses[j].x == x && horses[j].y == y && h <= horses[j].height)
                {
                    candidate.push_back(horses[j]);
                }
            }

            sort(candidate.begin(), candidate.end(), cmp);
            // 이동하려는 곳이 하얀색 칸 -> 순서 안뒤집고 넣어줌. 
            if(arr[nx][ny] == 0)
            {
                for(int j = 0; j < candidate.size(); j++)
                {
                    int id = candidate[j].id;
                    horses[id].x = nx;
                    horses[id].y = ny;
                    // 근데 방향은 안바뀜!
                    horses[id].height = check[nx][ny]++;
                    check[x][y]--;
                }
            } 
            // 이동하려는 곳이 빨간색 칸 -> 순서 뒤집고 넣어줌. 
            else 
            {
                for(int j = 0; j < candidate.size(); j++)
                {
                    int id = candidate[candidate.size() - 1 - j].id;
                    horses[id].x = nx;
                    horses[id].y = ny;
                    // 근데 방향은 안바뀜!
                    horses[id].height = check[nx][ny]++;
                    check[x][y]--;
                }
            }

            if(check[nx][ny] >= 4)
            {
                printf("%d\n", cnt);
                return 0;
            }
        }
    }

    cout << "-1\n";
    return 0;
}
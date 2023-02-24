#include <iostream>
#include <vector>
using namespace std;

struct Shark {
    int x;
    int y;
    int d;
    bool isAlive = true;
    int priority[5][4];
};

// 1 위, 2  아래, 3  왼쪽, 4 오른쪽
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

// (i, j)에 있는 냄새주인, 남은 시간
int gas[20][20][2];

int main()
{
    int n, m, k, tmp;
    cin >> n >> m >> k;
    vector<Shark> shark(m + 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> tmp;
            if(tmp > 0)
            {
                gas[i][j][0] = tmp;
                gas[i][j][1] = k;
                shark[tmp].x = i;
                shark[tmp].y = j;
            }
        }
    }

    for(int i = 1; i <= m; i++)
    {
        cin >> tmp;
        shark[i].d = tmp;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                cin >> shark[i].priority[j][k];
            }
        }
    }

    int time = 0;
    while(time < 1000)
    {
        time++;

        // 1. 상어가 이동한다
        for(int i = 1; i <= m; i++)
        {
            // 죽은애는 패스
            if(!shark[i].isAlive) continue;
            int x = shark[i].x, y = shark[i].y, d = shark[i].d;
            bool isDone = false;

            // 냄새 없는곳으로 갈 수 있으면 이동
            for(int j = 0; j < 4; j++)
            {
                int direction = shark[i].priority[d][j];
                int nx = x + dx[direction], ny = y + dy[direction];

                // 범위 벗어나거나 냄새가 남아있으면 바로 커뜨
                if(nx < 0 || nx == n || ny < 0 || ny == n || gas[nx][ny][1] > 0) continue;
                
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].d = direction;
                isDone = true;
                break;
            }
            if(isDone) continue;

            // 자기 냄새로라도 갈 수 있는지 체크
            for(int j = 0; j < 4; j++)
            {
                int direction = shark[i].priority[d][j];
                int nx = x + dx[direction], ny = y + dy[direction];

                // 범위 벗어나거나 자기 냄새가 아닌경우 커뜨
                if(nx < 0 || nx == n || ny < 0 || ny == n || gas[nx][ny][0] != i) continue;
                
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].d = direction;
                break;
            }
        }

        // 2. 냄새를 1씩 줄여준다.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(gas[i][j][1] > 0)
                {
                    gas[i][j][1]--;
                    if(gas[i][j][1] == 0)
                    {
                        gas[i][j][0] = 0;
                    }
                }
            }
        }

        // 3. 같은 위치에 겹치는 상어들 처리
        for(int i = 1; i <= m; i++)
        {
            // 죽은애는 패스
            if(!shark[i].isAlive) continue;
            int x = shark[i].x, y = shark[i].y;
            for(int j = i + 1; j <= m; j++)
            {
                if(!shark[j].isAlive) continue;
                if(shark[j].x == x && shark[j].y == y)
                {
                    shark[j].isAlive = false;
                }
            }
            gas[x][y][0] = i;
            gas[x][y][1] = k;
        }

        // 4. 끝났는지 체크
        bool isDone = true;
        for(int i = 2; i <= m; i++)
        {
            // 죽은애는 패스
            if(shark[i].isAlive)
            {
                isDone = false;
                break;
            }
        }

        if(isDone)
        {
            printf("%d\n", time);
            return 0;
        }
    }

    // 여기까지 왔으면 불가능
    printf("-1\n");
    return 0;
}
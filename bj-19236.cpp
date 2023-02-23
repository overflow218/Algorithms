#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

struct fish{
    int x;
    int y;
    int direction;
    int number;
    bool isAlive;
};

struct shark{
    int x;
    int y;
    int direction;
};

int ans = 0;

void find(vector<vector<int>> arr, vector<fish> sea, shark &s, int sum)
{
    // 1. 물고기의 이동.
    for(int i = 1; i <= 16; i++)
    {
        // 죽은 물고기는 패스
        if(!sea[i].isAlive) continue;
        int x = sea[i].x, y = sea[i].y, direction = sea[i].direction;

        for(int j = 0; j < 8; j++)
        {
            int nx = x + dx[(direction + j) % 8], ny = y + dy[(direction + j) % 8];

            // 벗어나거나 상어가 있는 곳이면 안됨.
            if(nx < 0 || nx == 4 || ny < 0 || ny == 4 || (nx == s.x && ny == s.y)) continue;

            // 빈칸이면 그냥 이동.
            if(arr[nx][ny] == 0)
            {
                arr[x][y] = 0;
                arr[nx][ny] = sea[i].number;
                sea[i].x = nx;
                sea[i].y = ny;
                sea[i].direction = (direction + j) % 8;
            } 
            // 물고기 있는 칸이면 서로 바꿔줘야함. 
            else 
            {
                int opposite = arr[nx][ny];
                sea[opposite].x = x;
                sea[opposite].y = y;
                arr[x][y] = opposite;

                arr[nx][ny] = sea[i].number;
                sea[i].x = nx;
                sea[i].y = ny;
                sea[i].direction = (direction + j) % 8;
            }
            break;
        }
    }

    // 2. 상어의 이동
    bool isDone = true;
    for(int i = 1; i < 4; i++)
    {
        int x = s.x, y = s.y, direction = s.direction;
        int nx = x + dx[s.direction] * i, ny = y + dy[s.direction] * i;
        // 범위 벗어나거나 빈칸인 경우는 패스
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || arr[nx][ny] == 0) continue;

        isDone = false;
        s.x = nx;
        s.y = ny;
        int fishNumber = arr[nx][ny];
        s.direction = sea[fishNumber].direction;
        int add = sea[fishNumber].number;
        sea[fishNumber].isAlive = false;
        arr[nx][ny] = 0;

        find(arr, sea, s, sum + add);

        s.x = x;
        s.y = y;
        s.direction = direction;
        arr[nx][ny] = fishNumber;
        sea[fishNumber].isAlive = true;
    }

    if(isDone)
    {
        ans = max(ans, sum);
    }
}

int main()
{
    vector<vector<int>> arr(4, vector<int>(4));
    vector<fish> sea(17);

    int a, b;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> a >> b;
            b %= 8;
            fish newFish = {i, j, b, a, true};
            sea[a] = newFish;
            arr[i][j] = a;
        }
    }

    shark s = {0, 0, sea[arr[0][0]].direction};
    ans += sea[arr[0][0]].number;
    sea[arr[0][0]].isAlive = false;
    arr[0][0] = 0;
    find(arr, sea, s, ans);
    cout << ans << "\n";
    return 0;
}
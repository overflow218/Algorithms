#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int r, c, k;
// (x, y) - (i, j) 칸 사이에 벽이 있는지 유무
bool isBlocked[24][24][24][24] = {false};
// (x1, y1), (x2, y2) 사이에 온도 조절이 일어났는지 여부
bool isChecked[24][24][24][24] = {false};
// 온도 담고 이씀
int arr[24][24] = {0};
// 기본 온풍기 방향
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
// 방향별 확산 및 벽체크
int sx[5][3] = {{0, 0, 0}, {-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};
int sy[5][3] = {{0, 0, 0}, {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1}};

struct Heater{
    int x;
    int y;
    int d; // 방향
};

int tmpHeat[24][24] = {0};
void heat(int x, int y, int d, int cnt)
{
    // 범위 벗어나거나 다 채웠으면 종료
    if(x == 0 || x > r || y == 0 || y > c || cnt == 0) return;
    tmpHeat[x][y] = cnt;

    // 지금 벽 막혀있는거 대비가 하나도 안되어있음. 그거 손봐주기
    for(int i = 0; i < 3; i++)
    {
        int nx = x + sx[d][i], ny = y + sy[d][i];
        if(i == 1)
        {
            if(isBlocked[x][y][nx][ny]) continue;
        } else 
        {
            if(d <= 2)
            {
                int tx = x + sx[d][i], ty = y;
                if(isBlocked[x][y][tx][ty] || isBlocked[tx][ty][nx][ny]) continue;
            } else 
            {
                int tx = x, ty = y + sy[d][i];
                if(isBlocked[x][y][tx][ty] || isBlocked[tx][ty][nx][ny]) continue;
            }
        }
        // 막히지 않은 경우에만 진행!
        heat(nx, ny, d, cnt - 1);
    }
}

// 온도 체크해야하는 방
vector<pair<int, int>> checkList;
// 히터정보 담고있는 벡터
vector<Heater> heaters;

int main()
{
    int w, x, y, t, tmp;
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> tmp;
            if(tmp == 5)
            {
                checkList.push_back(make_pair(i, j));
            } else if(tmp > 0)
            {
                Heater newHeater = {i, j, tmp};
                heaters.push_back(newHeater);
            }
        }
    }

    cin >> w;
    for(int i = 0; i < w; i++)
    {
        cin >> x >> y >> t;
        if(t == 0)
        {
            isBlocked[x][y][x - 1][y] = true;
            isBlocked[x - 1][y][x][y] = true;
        } else 
        {
            isBlocked[x][y][x][y + 1] = true;
            isBlocked[x][y + 1][x][y] = true;
        }
    }

    int chocolate = 0;

    while(chocolate < 101)
    {
        // 1. 온풍기 작동
        for(const auto & h: heaters)
        {
            int x = h.x, y = h.y, d = h.d;
            heat(x + dx[d], y + dy[d], d, 5);

            for(int i = 1; i <= r; i++)
            {
                for(int j = 1; j <= c; j++)
                {
                    if(tmpHeat[i][j] > 0)
                    {
                        arr[i][j] += tmpHeat[i][j];
                        tmpHeat[i][j] = 0;
                    }
                }
            }
        }

        // 2. 온도 조절
        memset(isChecked, 0, sizeof(isChecked));
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                for(int k = 1; k <= 4; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    // 이미 체크했거나 벽이 막혀있으면 건너뛰어야함.
                    if(x == 0 || x > r || y == 0 || y > c) continue;
                    if(isChecked[i][j][x][y] || isBlocked[i][j][x][y]) continue;
                    int diff = abs(arr[x][y] - arr[i][j]) / 4;
                    isChecked[i][j][x][y] = isChecked[x][y][i][j] = true;

                    if(arr[x][y] > arr[i][j])
                    {
                        tmpHeat[x][y] += -diff;
                        tmpHeat[i][j] += diff;
                    } else if(arr[x][y] < arr[i][j])
                    {
                        tmpHeat[x][y] += diff;
                        tmpHeat[i][j] += -diff;
                    }
                }
            }
        }


        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                arr[i][j] += tmpHeat[i][j];
                tmpHeat[i][j] = 0;
            }
        }

        // 3. 바깥쪽칸 온도 1감소
        for(int i = 2; i < r; i++)
        {
            if(arr[i][1] > 0) arr[i][1]--;
            if(arr[i][c] > 0) arr[i][c]--;
        }
        for(int j = 2; j < c; j++)
        {
            if(arr[1][j] > 0) arr[1][j]--;
            if(arr[r][j] > 0) arr[r][j]--;
        }
        arr[1][1] = max(0, arr[1][1] - 1);
        arr[1][c] = max(0, arr[1][c] - 1);
        arr[r][1] = max(0, arr[r][1] - 1);
        arr[r][c] = max(0, arr[r][c] - 1);

        // 4. 초콜릿 먹기
        chocolate++;

        // 5. 모든 체크칸 온도가 K이상인지 확인
        bool isDone = true;
        for(const auto & room:checkList)
        {
            int x = room.first, y = room.second;
            if(arr[x][y] < k)
            {
                isDone = false;
                break;
            }
        }

        if(isDone) break;
    }

    cout << chocolate << '\n';
    return 0;
}
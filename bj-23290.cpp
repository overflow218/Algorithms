#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// 상어의 좌표를 나타냄.
int sharkX, sharkY;
// 물고기 이동에 쓰임
int dx[] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

// 상어 이동에 쓰임
// 1부터 상 좌 하 우
int sx[] = {0, -1, 0, 1, 0};
int sy[] = {0, 0, -1, 0, 1};

struct Fish{
    int x;
    int y;
    int d;
};

vector<Fish> fish;
vector<Fish> tmpFish;
// 물고기 냄새 표시
int arr[5][5] = {0};
// 물고기 개수 표시
int fishCount[5][5] = {0};
// 이번에 상어가 지나가서 삭제되어야하면 컷
bool isDeleted[5][5] = {0};

// 상어가 이동하면서 방문한곳인지 표시
bool isVisited[5][5] = {0};

void find()
{
    int direction[3];
    vector<pair<int, int>> check(3);
    int ans = -1;
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 1; k <= 4; k++)
            {
                int tx = sharkX, ty = sharkY;
                direction[0] = i;
                direction[1] = j;
                direction[2] = k;
                bool isPossible = true;
                int cnt = 0;
                vector<pair<int, int>> tmp(3);
                for(int it = 0; it < 3; it++)
                {
                    int nx = tx + sx[direction[it]], ny = ty + sy[direction[it]];
                    if(nx == 0 || nx == 5 || ny == 0 || ny == 5)
                    {
                        isPossible = false;
                        break;
                    }
                    cnt += fishCount[nx][ny];
                    tmp[it] = make_pair(nx, ny);
                    tx = nx;
                    ty = ny;
                }

                if(tmp[0] == tmp[2])
                {
                    cnt -= fishCount[tmp[0].first][tmp[0].second];
                }

                if(isPossible && ans < cnt)
                {
                    ans = cnt;
                    check[0] = tmp[0];
                    check[1] = tmp[1];
                    check[2] = tmp[2];
                }
            }
        }
    }

    // 상어 좌표 바꿔줘야함. 
    sharkX = check[2].first, sharkY = check[2].second;
    // 물고기 냄새 표시
    for(int i = 0; i < 3; i++)
    {
        int tx = check[i].first, ty = check[i].second;
        isDeleted[tx][ty] = true;
    }
}

int main()
{
    int m, s, fx, fy, d;
    cin >> m >> s;
    for(int i = 0; i < m; i++)
    {
        cin >> fx >> fy >> d;
        Fish newFish = {fx, fy, d % 8};
        fish.push_back(newFish);
        fishCount[fx][fy]++;
    }

    cin >> sharkX >> sharkY;

    for(int it = 0; it < s; it++)
    {
        memset(isDeleted, false, sizeof(isDeleted));
        tmpFish.clear();

        // 1. 물고기 복제 
        for(int i = 0; i < fish.size(); i++)
        {
            int x = fish[i].x, y = fish[i].y, d = fish[i].d;
            Fish newFish = {x, y, d};
            tmpFish.push_back(newFish);
        }

        // 2. 물고기가 이동
        for(int i = 0; i < fish.size(); i++)
        {
            int x = fish[i].x, y = fish[i].y, d = fish[i].d;

            for(int j = 0; j < 8; j++)
            {
                int nd = (d + 7 * j) % 8;
                int nx = x + dx[nd], ny = y + dy[nd];
                if(nx == 0 || nx == 5 || ny == 0 || ny == 5 || (nx == sharkX && ny == sharkY) || arr[nx][ny] > 0) continue;
                fishCount[x][y]--;
                fishCount[nx][ny]++;
                fish[i].x = nx;
                fish[i].y = ny;
                fish[i].d = nd;
                break;
            }
        }

        // 4. 물고기 냄새부터 줄여주기
        for(int i = 1; i <= 4; i++)
        {
            for(int j = 1; j <= 4; j++)
            {
                if(arr[i][j] > 0) arr[i][j]--;
            }
        }
        // 3. 상어가 이동 & 물고기 냄새 표시
        find();

        // 복제한 물고기 포함해서 물고기 합치기
        // 삭제된곳에 있는 애들은 없애줘야함.
        for(int i = 0; i < fish.size(); i++)
        {
            if(!isDeleted[fish[i].x][fish[i].y])
            {
                tmpFish.push_back(fish[i]);
            } 
            // 물고기 냄새 남기기
            else 
            {
                arr[fish[i].x][fish[i].y] = 2;
            }
        }

        // 물고기 다시 바꿔주고 개수 갱신
        fish.clear();
        fish = vector<Fish>(tmpFish.begin(), tmpFish.end());
        memset(fishCount, 0, sizeof(fishCount));
        for(int i = 0; i < fish.size(); i++)
        {
            fishCount[fish[i].x][fish[i].y]++;
        }
    }

    // 남은 물고기수 출력
    printf("%d\n", fish.size());
    return 0;
}
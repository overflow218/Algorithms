#include <iostream>
#include <queue>
using namespace std;

char board[11][11] = {0};
int dx[] = {0, 0, 1, -1}; // 우, 좌, 하, 상
int dy[] = {1, -1, 0, 0};
int n, m;

struct Position {
    int rX;
    int rY;
    int bX;
    int bY;
};

int main()
{
    scanf("%d %d", &n, &m);
    pair<int, int> red, blue, hole;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", board[i]);
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'R')
            {
                red.first = i;
                red.second = j;
            } else if(board[i][j] == 'B')
            {
                blue.first = i;
                blue.second = j;
            } else if(board[i][j] == 'O')
            {
                hole.first = i;
                hole.second = j;
            }
        }
    }

    Position start = {red.first, red.second, blue.first, blue.second};
    queue<Position> q;
    q.push(start);
    
    int ans = 0;
    while(!q.empty() && ans <= 10)
    {
        int cnt = q.size();
        for(int iter = 0; iter < cnt; iter++)
        {
            Position tmp = q.front();
            int rX = tmp.rX, rY = tmp.rY, bX = tmp.bX, bY = tmp.bY;
            q.pop();
            if(rX == bX && rY == bY) continue;
            // 빨간거 안빠졌는데 파란 구슬 빠지는걸 고려를 안했넹...
            if(bX == hole.first && bY == hole.second) continue;
            if(rX == hole.first && rY == hole.second)
            {
                printf("%d\n", ans);
                return 0;
            }


            // 상하좌우 4가지 방향으로 기울여줘야하는데 이게 은근 귀찮네
            for(int i = 0; i < 4; i++)
            {
                int nrX = rX, nrY = rY, nbX = bX, nbY = bY;
                // 일단 빨간공, 파란공 둘다 최대한 끝까지 보내준다.
                for(int j = 1; j < 10; j++)
                {
                    int tX = rX + dx[i] * j, tY = rY + dy[i] * j;
                    // if(tX < 0 || tX == n || tY < 0 || tY == m || board[tX][tY] == '#') break;
                    if(board[tX][tY] == '#') break;
                    nrX = tX;
                    nrY = tY;
                    if(nrX == hole.first && nrY == hole.second) break;
                }

                for(int j = 1; j < 10; j++)
                {
                    int tX = bX + dx[i] * j, tY = bY + dy[i] * j;
                    // if(tX < 0 || tX == n || tY < 0 || tY == m || board[tX][tY] == '#') break;
                    if(board[tX][tY] == '#') break;
                    nbX = tX;
                    nbY = tY;
                    if(nbX == hole.first && nbY == hole.second) break;
                }

                // 위치가 같을때 옆에있떤 하나를 옆으로 보내준다. 다만 구멍에 빠진 경우는 제외
                if((nrX == nbX && nrY == nbY) && (nrX != hole.first || nrY != hole.second))
                {
                    // -> 오른쪽으로 기울인 경우
                    if(i == 0)
                    {
                        // 빨간게 더 오른쪽에 있었던 경우
                        if(rY > bY)
                        {
                            nbY--;
                        } else 
                        {
                            nrY--;
                        }
                    } else if(i == 1) // <- 왼쪽으로 기울이는 경우
                    {
                        // 빨간게 더 왼쪽에 있었던 경우
                        if(rY < bY)
                        {
                            nbY++;
                        } else 
                        {
                            nrY++;
                        }
                    } else if(i == 2) // 아래로 기울이는 경우
                    {
                        // 빨간게 더 위에 있었던
                        if(rX < bX)
                        {
                            nrX--;
                        } else 
                        {
                            nbX--;
                        }
                    } else // 위로 기울이는 경우
                    {
                        // 빨간게 더 위에 있었던
                        if(rX < bX)
                        {
                            nbX++;
                        } else 
                        {
                            nrX++;
                        }
                    }
                }

                Position next = {nrX, nrY, nbX, nbY};
                q.push(next);
            }
        }
        ans++;
    }
    
    // 여기까지 왔으면 불가능
    printf("-1\n");
    return 0;
}
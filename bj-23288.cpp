#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int arr[25][25] = {0};
bool isVisited[25][25];

int find(int x, int y, int source)
{
    if(x == 0 || x > n || y == 0 || y > m || isVisited[x][y] || arr[x][y] != source) return 0;
    int ret = 1;
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        ret += find(x + dx[i], y + dy[i], source);
    }
    return ret;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int x = 1, y = 1, d = 0;
    int back = 2, front = 5, top = 1, bottom = 6, left = 4, right = 3;

    int ans = 0;
    for(int i = 0; i < k; i++)
    {
        // 1. 이동
        int nx = x + dx[d], ny = y + dy[d];
        // 칸이 없으니 반대로 이동
        if(nx == 0 || nx > n || ny == 0 || ny > m)
        {
            d = (d + 2) % 4;
            nx = x + dx[d], ny = y + dy[d];
        }
        x = nx; y = ny;

        int nextBack = back, nextFront = front, nextTop = top, nextBottom = bottom, nextLeft = left, nextRight = right;
        // 동쪽
        if(d == 0)
        {
            top = nextLeft;
            left = nextBottom;
            right = nextTop;
            bottom = nextRight;
        }
        // 서쪽
        if(d == 2)
        {
            bottom = nextLeft;
            right = nextBottom;
            left = nextTop;
            top = nextRight;
        }
        // 남쪽
        if(d == 1)
        {
            back = nextBottom;
            top = nextBack;
            front = nextTop;
            bottom = nextFront;
        }
        // 북쪽
        if(d == 3)
        {
            front = nextBottom;
            bottom = nextBack;
            back = nextTop;
            top = nextFront;
        }

        // 2. 점수획득
        memset(isVisited, 0, sizeof(isVisited));
        int cnt = find(x, y, arr[x][y]);
        ans += cnt * arr[x][y];

        // 3. 이동방향 수정
        // 주사위 바닥 > 현재 칸 -> 시계방향 90
        if(bottom > arr[x][y])
        {
            d = (d + 1) % 4;
        } 
        // 주사위 바닥 < 현재 칸 -> 반시계방향 90
        else if(bottom < arr[x][y])
        {
            d = (d + 3) % 4;
        }
    }

    cout << ans << '\n';
    return 0;
}
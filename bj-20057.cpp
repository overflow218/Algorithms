#include <iostream>
using namespace std;

int arr[510][510] = {0};
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// 10, 10, 7, 7, 1, 1, 2, 2, 5, a
int sx[4][10] = {{-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, {1, 1, 0, 0, -1, -1, 0, 0, 2, 1}, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, {-1, -1, 0, 0, 1, 1, 0, 0, -2, -1}};
int sy[4][10] = {{-1, -1, 0, 0, 1, 1, 0, 0, -2, -1}, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, {1, 1, 0, 0, -1, -1, 0, 0, 2, 1}, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}};
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int x = n / 2 + 1, y = n / 2 + 1, direction = 0, limit = 1;

    // 이게 2가 될때마다 limit이 1씩 늘어나야함. 
    int sizeCounter = 0;
    // 이동횟수를 나타냄.
    int cnt = 0;
    int ans = 0;

    while(x != 1 || y != 1)
    {
        // 1. 일단 모래를 이동시킨다. 
        int nx = x + dx[direction], ny = y + dy[direction];
        int s1 = arr[nx][ny] / 100;
        int s2 = arr[nx][ny] * 2 / 100;
        int s5 = arr[nx][ny] / 20;
        int s7 = arr[nx][ny] * 7 / 100;
        int s10 = arr[nx][ny] / 10;
        int a = arr[nx][ny] - s5 - 2 * (s1 + s2 + s7 + s10);
        int sand[] = {s10, s10, s7, s7, s1, s1, s2, s2, s5, a};
        
        arr[nx][ny] = 0;
        for(int i = 0; i < 10; i++)
        {
            int tx = nx + sx[direction][i], ty = ny + sy[direction][i];
            if(tx < 1 || tx > n || ty < 1 || ty > n)
            {
                ans += sand[i];
            } else 
            {
                arr[tx][ty] += sand[i];
            }
        }


        x = nx, y = ny;
        cnt++;
        if(sizeCounter == 2)
        {
            limit++;
            sizeCounter = 0;
        }
        if(cnt == limit)
        {
            direction = (direction + 1) % 4;
            sizeCounter++;
            cnt = 0;
        }
    }

    cout << ans << '\n';


    return 0;
}
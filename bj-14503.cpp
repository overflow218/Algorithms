#include <iostream>
using namespace std;

int arr[50][50];
bool isClean[50][50] = {false};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int n, m, x, y, d, ans = 0;
    cin >> n >> m;
    cin >> x >> y >> d;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    while(true)
    {
        // 0. 끝났는지 체크
        if(arr[x][y] == 1) break;

        // 1. 청소
        if(!isClean[x][y])
        {
            isClean[x][y] = true;
            ans++;
            arr[x][y] = 2;
        }
        
        bool moveBack = true;
        // 2. 주변 4칸 체크
        for(int i = 1; i < 5; i++)
        {   
            // 반시계로 돌아야함
            int nd = (d + 4 - i) % 4;
            int nx = x + dx[nd], ny = y + dy[nd];
            // 빈칸이면서 더러운곳일때
            if(arr[nx][ny] == 0 && !isClean[nx][ny])
            {
                x = nx; y = ny; d = nd;
                moveBack = false;
                break;
            }
        }

        // 3. 없으면 후진
        if(moveBack)
        {
            x = x - dx[d]; y = y - dy[d];
        }
    }

    cout << ans << '\n';
    return 0;
}
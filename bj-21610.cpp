#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[50][50];
int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
// 대각선 표현
int sx[] = {-1, -1, 1, 1};
int sy[] = {-1, 1, -1, 1};
bool isDeleted[50][50];

vector<pair<int, int>> clouds;
int main()
{
    int n, m, d, s;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    clouds.push_back(make_pair(n-2, 0));
    clouds.push_back(make_pair(n-2, 1));
    clouds.push_back(make_pair(n-1, 0));
    clouds.push_back(make_pair(n-1, 1));

    for(int it = 0; it < m; it++)
    {
        cin >> d >> s;
        memset(isDeleted, 0, sizeof(isDeleted));
        // 1. 구름 이동
        for(int i = 0; i < clouds.size(); i++)
        {
            // 1. 구름 이동
            int x = clouds[i].first, y = clouds[i].second;
            int nx = (x + s * dx[d] + s * n) % n;
            int ny = (y + s * dy[d] + s * n) % n;
            clouds[i].first = nx;
            clouds[i].second = ny;
            x = nx; y = ny;
        }

        // 2. 바구니에 물주기 && 4. 물복사 마법 시전
        for(int i = 0; i < clouds.size(); i++)
        {
            int x = clouds[i].first, y = clouds[i].second;
            arr[x][y]++;
            isDeleted[x][y] = true;
        }

        //4. 물복사 마법 시전
        for(int i = 0; i < clouds.size(); i++)
        {
            int x = clouds[i].first, y = clouds[i].second;
            int cnt = 0;
            for(int j = 0; j < 4; j++)
            {
                int nx = x + sx[j], ny = y + sy[j];
                if(nx < 0 || nx == n || ny < 0 || ny == n) continue;
                if(arr[nx][ny] > 0) cnt++;
            }
            arr[x][y] += cnt;
        }

        // 3. 구름 없애기 
        clouds.clear();

        // 5. 새로운 구름 만들기
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] >= 2 && !isDeleted[i][j])
                {
                    // printf("%d, %d는 새로운 구름이 생김\n", i + 1, j + 1);
                    clouds.push_back(make_pair(i, j));
                    arr[i][j] -= 2;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans += arr[i][j];
        }
    }

    cout << ans << '\n';
    return 0;
}
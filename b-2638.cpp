#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m, tmp;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isOutsideCheese(int x, int y, vector<vector<int>>& arr)
{
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        int nX= x + dx[i];
        int nY = y + dy[i];
        if(arr[nX][nY] == -1) cnt++;
    }
    return cnt >= 2;
}

void checkAir(int x, int y, vector<vector<int>>& arr)
{
    if(x < 0 || x == n || y < 0 || y == m || arr[x][y] != 0) return;
    arr[x][y] = -1;
    for(int i = 0; i < 4; i++)
    {
        checkAir(x + dx[i], y + dy[i], arr);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    // 치즈 1, 안쪽 공기 0, 바깥쪽 공기 -1   
    vector<vector<int>> arr(n);
    deque<pair<int, int>> cheese;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            arr[i].push_back(tmp);
            if(tmp == 1)
            {
                cheese.push_back(make_pair(i, j));
            }
        }
    }
    
    int cheeseCount = cheese.size();
    int ans = 0;
    checkAir(0, 0, arr);
    while(cheeseCount > 0)
    {
        ans++;
        vector<pair<int, int>> melting;
        int limit = cheese.size();
        for(int i = 0; i < limit; i++)
        {
            pair<int, int> cur = cheese.front();
            cheese.pop_front();
            int x = cur.first, y = cur.second;
            if(isOutsideCheese(x, y, arr))
            {
                melting.push_back(cur);
            } else 
            {
                cheese.push_back(cur);
            }
        }

        cheeseCount -= melting.size();
        for(int i = 0; i < melting.size(); i++)
        {
            arr[melting[i].first][melting[i].second] = 0;
        }

        for(int i = 0; i < melting.size(); i++)
        {
            checkAir(melting[i].first, melting[i].second, arr);
        }
    }
    printf("%d\n", ans);
    return 0;
}
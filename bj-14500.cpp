#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int ans = 0, n, m;
int dx[] = {1, -1, 0};
int dy[] = {0, 0, 1};
int dx2[][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}};
int dy2[][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}};

int arr[500][500] = {0};
bool isVisited[500][500] = {false};

int calculate(vector<pair<int, int> > &chosen)
{
    int tmp = 0;
    for(int i = 0; i < 4; i++)
    {
        tmp += arr[chosen[i].first][chosen[i].second];
    }
    return tmp;
}

void go(int x, int y, vector<pair<int, int> > &chosen)
{
    if(chosen.size() == 4)
    {
        ans = max(ans, calculate(chosen));
        return;
    }
    if(x < 0 || x >= n || y < 0 || y >= m || isVisited[x][y]) return;
    isVisited[x][y] = true;
    chosen.push_back(make_pair(x, y));
    for(int i = 0; i < 3; i++)
    {
        go(x + dx[i], y + dy[i], chosen);
    }
    chosen.pop_back();
    isVisited[x][y] = false;
}

void go2(int x, int y, vector<pair<int, int> > &chosen)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int tx = x + dx2[i][j], ty = y + dy2[i][j];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m) break;
            chosen.push_back(make_pair(tx, ty));
        }
        if(chosen.size() == 4)
        {
            ans = max(ans, calculate(chosen));
        }
        chosen.clear();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    vector<pair<int, int> > vec;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            go(i, j, vec);
            go2(i, j, vec);
        }
    }
    printf("%d\n", ans);
    return 0;
}
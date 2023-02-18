#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[50][50];
int isVisited[50][50] = {false};
int n, l, r;
bool isDone = true;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int find(int x, int y, vector<pair<int, int>> &chosen)
{
    if(isVisited[x][y]) return 0;
    isVisited[x][y] = true;
    chosen.push_back(make_pair(x, y));
    int ret = arr[x][y];

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx == n || ny < 0 || ny == n || isVisited[nx][ny]) continue;
        int diff = abs(arr[x][y] - arr[nx][ny]);
        if(l <= diff && diff <= r)
        {
            ret += find(nx, ny, chosen);
        }
    }
    return ret;
}

int main()
{
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int time = 0;
    while(time <= 2000)
    {
        memset(isVisited, 0, sizeof(isVisited));
        isDone = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!isVisited[i][j])
                {
                    vector<pair<int, int>> chosen;
                    int sum = find(i, j, chosen);
                    if(chosen.size() > 1)
                    {
                        isDone = false;
                        int next = sum / (int)chosen.size();
                        for(auto & ho:chosen)
                        {
                            arr[ho.first][ho.second] = next;
                        }
                    }
                }
            }
        }

        // 더이상 이동 없으면 종료
        if(isDone) break;
        time++;
    }
    cout << time << '\n';
    return 0;
}
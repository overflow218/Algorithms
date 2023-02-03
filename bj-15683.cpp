#include <iostream>
#include <vector>
using namespace std;

int n, m, wall = 0, ans = 100;
int board[8][8] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void check(vector<pair<int, int>> &camera, vector<int> &directions)
{
    bool isVisited[8][8] = {false};
    int cnt = 0;
    for(int i = 0; i < camera.size(); i++)
    {
        int x = camera[i].first, y = camera[i].second;
        int type = board[x][y];
        int direction = directions[i];
        bool isOkay[4] = {false, false, false, false};
        switch (type)
        {
            case 1:
                isOkay[direction] = true;
                break;
            case 2:
                if(direction == 0)
                {
                    isOkay[0] = isOkay[1] = true;
                } else 
                {
                    isOkay[2] = isOkay[3] = true;
                }
                break;
            case 3:
                if(direction == 0)
                {
                    isOkay[0] = isOkay[2] = true;
                } else if(direction == 1)
                {
                    isOkay[2] = isOkay[1] = true;
                } else if(direction == 2)
                {
                    isOkay[1] = isOkay[3] = true;
                } else 
                {
                    isOkay[3] = isOkay[0] = true;
                }
                break;
            case 4:
                if(direction == 0)
                {
                    isOkay[0] = isOkay[1] = isOkay[2] = true;
                } else if(direction == 1)
                {
                    isOkay[0] = isOkay[1] = isOkay[3] = true;
                } else if(direction == 2)
                {
                    isOkay[0] = isOkay[2] = isOkay[3] = true;
                } else 
                {
                    isOkay[3] = isOkay[1] = isOkay[2] = true;
                }
                break;
            default:
                isOkay[0] = isOkay[1] = isOkay[2] = isOkay[3] = true;
                break;
        }

        for(int iter = 0; iter < 4; iter++)
        {
            if(!isOkay[iter]) continue;
            for(int k = 1; k < 8; k++)
            {
                int nx = x + dx[iter] * k, ny = y + dy[iter] * k;
                if(nx < 0 || nx == n || ny < 0 || ny == m || board[nx][ny] == 6) break;
                if(board[nx][ny] == 0 && !isVisited[nx][ny])
                {
                    isVisited[nx][ny] = true;
                    cnt++;
                }
            }
        }
    }
    ans = min(ans, n * m - wall - (int)camera.size() - cnt);
}

void find(vector<pair<int, int>> &camera, vector<int> &directions)
{
    if(directions.size() == camera.size())
    {
        check(camera, directions);
    } else 
    {
        int idx = directions.size();
        int type = board[camera[idx].first][camera[idx].second];
        int ways = type == 5 ? 1 : (type == 2 ? 2 : 4);
        for(int i = 0; i < ways; i++)
        {
            directions.push_back(i);
            find(camera, directions);
            directions.pop_back();
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> camera;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 6)
            {
                wall++;
            } else if(board[i][j])
            {
                camera.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> directions;
    find(camera, directions);
    printf("%d\n", ans);
    return 0;
}
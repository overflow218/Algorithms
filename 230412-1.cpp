#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

/*
총 2번의 탐색이 필요함
1. 시작점 -> 레버
2. 레버 -> 끝점
*/

bool isVisited[100][100];
// 맵이 n * m 크기라고 하자
int sX, sY, eX, eY, lX, lY, n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 최단거리로 가야하니까 dfs를 돌려야함. 
bool leverDone = false;
bool isFinished = false;

queue<pair<int, int>> q;
int solution(vector<string> maps) {
    n = maps.size(); m = maps[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(maps[i][j] == 'S')
            {
                sX = i; sY = j;
            }
            if(maps[i][j] == 'E')
            {
                eX = i; eY = j;
            }
            if(maps[i][j] == 'L')
            {
                lX = i; lY = j;
            }
        }
    }
    
    int answer = 0;
    q.push(make_pair(sX, sY));
    memset(isVisited, false, sizeof(isVisited));
    while(!q.empty())
    {
        int limit = q.size();
        for(int it = 0; it < limit; it++)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            // 범위 벗어나는 경우 종료
            if(x < 0 || x == n || y < 0 || y == m) continue;
            // 이미 방문한점이거나 벽이면 종료
            if(maps[x][y] == 'X' || isVisited[x][y]) continue;

            isVisited[x][y] = true;
            if(x == lX && y == lY)
            {
                // q비우고 다시 시작하기
                q = queue<pair<int, int>>();
                leverDone = true;
                break;
            }
            for(int i = 0; i < 4; i++)
            {
                q.push(make_pair(x + dx[i], y + dy[i]));
            }
        }
        if(leverDone) break;
        answer++;
    }
    
    // 레버근처도 못가는 경우
    if(!leverDone)
    {
        return -1;
    }

    q.push(make_pair(lX, lY));
    memset(isVisited, false, sizeof(isVisited));
    while(!q.empty())
    {
        int limit = q.size();
        for(int it = 0; it < limit; it++)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            // 범위 벗어나는 경우 종료
            if(x < 0 || x == n || y < 0 || y == m) continue;
            // 이미 방문한점이거나 벽이면 종료
            if(maps[x][y] == 'X' || isVisited[x][y]) continue;

            isVisited[x][y] = true;
            if(x == eX && y == eY)
            {
                return answer;
            }
            for(int i = 0; i < 4; i++)
            {
                q.push(make_pair(x + dx[i], y + dy[i]));
            }
        }
        answer++;
    }
    
    return -1;
}
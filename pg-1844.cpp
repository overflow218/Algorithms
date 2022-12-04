#include<vector>
#include <queue>
using namespace std;

queue<vector<int>> q;
bool isVisited[101][101] = {false};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size(), m = maps[0].size();
    q.push({0, 0, 0});
    isVisited[0][0] = true;
    while(!q.empty())
    {
        vector<int> current = q.front();
        int x = current[0], y = current[1], cnt = current[2];
        q.pop();
        if(x == n - 1 && y == m - 1)
        {
            return cnt + 1;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || isVisited[nx][ny] || !maps[nx][ny]) continue;
            q.push({nx, ny, cnt + 1});
            isVisited[nx][ny] = true;
        }
    }
    return answer;
}
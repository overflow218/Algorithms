#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int sx[2] = {0, 1};
int sy[2] = {1, 0};

// 0 은 가로, 1은 세로인 상태를 의미.
bool isVisited[100][100][2] = {false};
struct point {
    int x;
    int y;
    int direction;
};

queue<point> q;
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    q.push(point{0, 0, 0});
    while(!q.empty())
    {
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            point tmp = q.front();
            q.pop();
            int x = tmp.x, y = tmp.y, d = tmp.direction;
            int x2 = x + sx[d], y2 = y + sy[d];
            
            if(x < 0 || x == n || y < 0 || y == n) continue;
            if(x2 < 0 || x2 == n || y2 < 0 || y2 == n) continue;
            if(isVisited[x][y][d]) continue;
            if(board[x][y] == 1 || board[x2][y2] == 1) continue;
            
            isVisited[x][y][d] = true;
            if((x == n - 1 && y == n - 1) || (x2 == n - 1&& y2 == n - 1)) return answer;
            
            // 지금방향 그대로
            for(int j = 0; j < 4; j++)
            {
                q.push(point{x + dx[j], y + dy[j], d});
            }
            // 회전할 수 있다면 회전을 시도해본다
            // 가로 방향이었을때
            if(d == 0)
            {
                // 아래로 회전 시도
                if(x < n - 1 && (board[x + 1][y] == 0 && board[x + 1][y + 1] == 0))
                {
                    q.push(point{x, y, 1});
                    q.push(point{x2, y2, 1});
                }
                // 위로 회전 시도
                if(x > 0 && (board[x - 1][y] == 0 && board[x - 1][y + 1] == 0))
                {
                    q.push(point{x - 1, y, 1});
                    q.push(point{x - 1, y + 1, 1});
                }
            }
            
            // 세로 방향이었을때
            if(d == 1)
            {
                // 오른쪽으로 회전 시도
                if(y < n - 1 && (board[x][y + 1] == 0 && board[x + 1][y + 1] == 0))
                {
                    q.push(point{x, y, 0});
                    q.push(point{x2, y2, 0});
                }
                // 왼쪽으로 회전 시도
                if(y > 0 && (board[x][y - 1] == 0 && board[x + 1][y - 1] == 0))
                {
                    q.push(point{x, y - 1, 0});
                    q.push(point{x + 1, y - 1, 0});
                }
            }
        }
        answer++;
    }
    return answer;
}
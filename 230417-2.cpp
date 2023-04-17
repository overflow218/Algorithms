#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// h * w의 보드라고 가정
int h, w;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> cache = vector<vector<int>> (100, vector<int>(100, 987654321));
queue<pair<int, int>> q;
set<pair<int, int>> s;
int solution(vector<string> board) {
    int answer = 0;
    int x, y;
    h = board.size(); w = board[0].size();
    
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(board[i][j] == 'R')
            {
                x = i;
                y = j;
            }
        }
    }
    
    q.push(make_pair(x, y));
    while(!q.empty())
    {
        int limit = q.size();
        s.clear();
        for(int i = 0; i < limit; i++)
        {
            x = q.front().first, y = q.front().second;
            q.pop();

            if(cache[x][y] <= answer) continue;
            if(board[x][y] == 'G') return answer;            
            cache[x][y] = answer;
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 100; k++)
                {
                    int nx = x + k * dx[j], ny = y + k * dy[j];
                    if(nx < 0 || nx == h || ny < 0 || ny == w || board[nx][ny] == 'D')
                    {
                        s.insert(make_pair(x + (k - 1) * dx[j], y + (k - 1) * dy[j]));
                        break;
                    }
                }
            }
        }
        for(auto it = s.begin(); it != s.end(); it++)
        {
            q.push(*it);
        }
        answer++;
    }
    return -1;
}
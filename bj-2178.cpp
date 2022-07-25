#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

class point{
    public: 
        int x;
        int y;
        int cnt;
        point(int x, int y, int cnt)
        {
            this -> x = x;
            this -> y = y;
            this -> cnt = cnt;
        }
};

queue<struct point> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool board[100][100] = {false};
bool isVisited[100][100] = {false};
int n, m;
char s[101];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j] == '1' ? true : false;
        }
    }
    
    q.push(point(0, 0, 1));
    while(!q.empty())
    {
        point current = q.front();
        q.pop();
        int x = current.x, y = current.y, cnt = current.cnt;
        if(x < 0 || x >= n || y < 0 || y >= m) continue;
        if(!board[x][y] || isVisited[x][y]) continue;
        if(x == n-1 && y == m-1)
        {
            printf("%d\n", cnt);
            return 0;
        }
        isVisited[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            q.push(point(x + dx[i], y + dy[i], cnt + 1));
        }
    }

    return 0;

}
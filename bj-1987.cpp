#include <iostream>
#include <cstdio>
using namespace std;

int r, c;
char board[21][21] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
// 야무지게 비트마스크로 대입해서 풀면 좋을듯?

int find(int x, int y, int cnt, int check)
{
    if(x < 0 || x >= r || y < 0 || y >=c) return cnt;
    int idx = board[x][y] - 'A';

    // 이미 방문한 점인 경우 
    if(check & (1 << idx))
    {
        return cnt;
    }
    // 처음 방문하는 경우. 
    int ret = cnt + 1;
    for(int i = 0; i < 4; i++)
    {
        ret = max(ret, find(x + dx[i], y + dy[i], cnt + 1, check | (1 << idx)));
    }
    return ret;
}

int main()
{
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
    {
        scanf("%s", board[i]);
    }
    printf("%d\n", find(0, 0, 0, 0));
    return 0;
}
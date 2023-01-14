#include <iostream>
#include <map>
using namespace std;

map<char, int> direction;
char arr[1000][1001] = {0};
int isVisited[1000][1001] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, cnt = 0;
// R, L, D, U
void check(int x, int y, int flag)
{
    if(isVisited[x][y] != 0)
    {
        if(isVisited[x][y] == flag)
        {
            cnt++;
        }
        return;
    }
    isVisited[x][y] = flag;
    check(x + dx[direction[arr[x][y]]], y + dy[direction[arr[x][y]]], flag);
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    direction['R'] = 0;
    direction['L'] = 1;
    direction['D'] = 2;
    direction['U'] = 3;

    int flag = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!isVisited[i][j])
            {
                check(i, j, flag++);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
/*
3 4
DLLL
DULU
RRRU
*/
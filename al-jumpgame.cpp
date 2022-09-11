#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c, n;
int board[100][100] = {0};
// (i,j) 에서 (n-1, n-1) 도달 가능여부를 표현
// 아직 미확인 -1, 불가능 0, 가능 1
int cache[100][100] = {0};

int find(int x, int y)
{
    if(x >= n || y >= n) return 0;
    if(x == n - 1 && y == n - 1) return 1;
    int & ret = cache[x][y];
    if(ret != -1) return ret;
    return ret = find(x + board[x][y], y) | find(x , y + board[x][y]);
}

int main()
{
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        memset(cache, -1, sizeof(cache));
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &board[i][j]);
            }
        }
        string ans = find(0, 0) ? "YES" : "NO";
        printf("%s\n", ans.c_str());
    }
    return 0;
}
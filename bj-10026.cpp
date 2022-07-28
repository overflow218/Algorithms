#include <iostream>
#include <cstdio>
using namespace std;

int n;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char arr[105][105] = {0};
bool normalVisited[100][100] = {false};
bool disabledVisited[100][100] = {false};

void go1(int x, int y, char check)
{
    if(x < 0 || x >= n || y < 0 || y >= n || normalVisited[x][y] || arr[x][y] != check) return;
    normalVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        go1(x + dx[i], y + dy[i], check);
    }
}

void go2(int x, int y, char check)
{
    if(x < 0 || x >= n || y < 0 || y >= n || disabledVisited[x][y]) return;
    if(check != arr[x][y] && (check == 'B' || arr[x][y] == 'B')) return;
    disabledVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        go2(x + dx[i], y + dy[i], check);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!normalVisited[i][j])
            {
                cnt1++;
                go1(i, j, arr[i][j]);
            }
            if(!disabledVisited[i][j])
            {
                cnt2++;
                go2(i, j, arr[i][j]);
            }
        }
    }
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}
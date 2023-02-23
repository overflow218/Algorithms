#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, height = 0, ans = 1;
bool isVisited[100][100];
int arr[100][100];

void check(int x, int y, int target)
{
    if(x < 0 || x == n || y < 0 || y == n || isVisited[x][y] || arr[x][y] <= target) return;
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        check(x + dx[i], y + dy[i], target);
    }
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            height = max(height, arr[i][j]);
        }
    }

    for(int target = 1; target < height; target++)
    {
        memset(isVisited, 0, sizeof(isVisited));
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] > target && !isVisited[i][j])
                {
                    check(i, j, target);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}
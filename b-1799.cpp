#include <iostream>
#include <vector>
using namespace std;

int arr[10][10] = {0};
int n;
vector<pair<int, int>> point;

int queen(int idx, int cnt)
{
    if(idx == point.size()) return cnt;
    int ret = cnt;
    for(int i = idx; i < point.size(); i++)
    {
        int x = point[i].first, y = point[i].second;
        bool isPossible = true;
        // 왼쪽 위 대각선 체크
        while(x >= 0 && y >= 0)
        {
            if(arr[x][y] == 2)
            {
                isPossible = false;
                break;
            }
            x--;
            y--;
        }
        x = point[i].first, y = point[i].second;
        // 오른쪽 위 대각선 체크
        while(isPossible && x >= 0 && y < n)
        {
            if(arr[x][y] == 2)
            {
                isPossible = false;
                break;
            }
            x--;
            y++;
        }
        if(isPossible)
        {
            x = point[i].first, y = point[i].second;
            arr[x][y] = 2;
            ret = max(ret, queen(i + 1, cnt + 1));
            arr[x][y] = 1;
        }
    }
    return ret;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j])
            {
                point.push_back(make_pair(i, j));
            }
        }
    }
    printf("%d\n", queen(0, 0));
    return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/
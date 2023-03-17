#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

int arr[52][52];
int spare[52][52];
vector<vector<int>> rotation;

void rotate(int r, int c, int s)
{
    for(int k = 1; k <= s; k++)
    {
        int leftTop = arr[r - k][c - k];
        int rightTop = arr[r - k][c + k];
        int leftBottom = arr[r + k][c - k];
        int rightBottom = arr[r + k][c + k];
        
        // 윗줄
        for(int j = c + k - 1; j > c - k; j--)
        {
            arr[r - k][j + 1] = arr[r - k][j];
        }
        arr[r - k][c - k + 1] = leftTop;
        // 오른쪽
        for(int row = r + k - 1; row > r - k; row--)
        {
            arr[row + 1][c + k] = arr[row][c + k];
        }
        arr[r - k + 1][c + k] = rightTop;

        // 밑줄
        for(int j = c - k + 1; j < c + k; j++)
        {
            arr[r + k][j - 1] = arr[r + k][j];
        }
        arr[r + k][c + k - 1] = rightBottom;

        // 왼쪽
        for(int row = r - k + 1; row < r + k; row++)
        {
            arr[row - 1][c - k] = arr[row][c - k];
        }
        arr[r + k - 1][c - k] = leftBottom;
    }
}

int main()
{
    int r, c, s;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            spare[i][j] = arr[i][j];
        }
    }

    vector<int> order;
    for(int i = 0; i < k; i++)
    {
        cin >> r >> c >> s;
        rotation.push_back({r, c, s});
        order.push_back(i);
    }
    int ans = 987654321;

    do {
        memcpy(arr, spare, sizeof(arr));

        for(int i = 0; i < k; i++)
        {
            rotate(rotation[order[i]][0], rotation[order[i]][1], rotation[order[i]][2]);
        }
        for(int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for(int j = 1; j <= m; j++)
            {
                cnt += arr[i][j];
            }
            ans = min(ans, cnt);
        }
    } while(next_permutation(order.begin(), order.end()));

    printf("%d\n", ans);
    return 0;
}
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int arr[64][64];
int square[] = {1, 2, 4, 8, 16, 32, 64};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, q, l, sum = 0, ans = 0;
bool isVisited[64][64] = {false};

int find(int x, int y)
{
    if(x < 0 || x == n || y < 0 || y == n || isVisited[x][y] || arr[x][y] == 0) return 0;
    int ret = 1;
    sum += arr[x][y];
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        ret += find(x + dx[i], y + dy[i]);
    }
    return ret;
}

int main()
{
    cin >> n >> q;
    n = square[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int it = 0; it < q; it++)
    {
        cin >> l;
        l = square[l];
        int tmp[64][64];

        
        if(l > 1)
        {
            vector<int> even;
            vector<int> odd;

            for(int i = 0; i < n; i += l)
            {
                if(i % 2 == 0)
                {
                    even.push_back(i);
                } else 
                {
                    odd.push_back(i);
                }
            }

            // 격자부분을 시계방향으로 90도 회전
            for(int i = 0; i < even.size(); i++)
            {
                for(int j = 0; j < even.size(); j++)
                {
                    int x = even[i], y = even[j];
                    for(int a = 0; a < l; a++)
                    {
                        for(int b = 0; b < l; b++)
                        {
                            tmp[x + b][y + l - 1 - a] = arr[x + a][y + b];
                        }
                    }
                }
            }

            for(int i = 0; i < odd.size(); i++)
            {
                for(int j = 0; j < odd.size(); j++)
                {
                    int x = odd[i], y = odd[j];
                    for(int a = 0; a < l; a++)
                    {
                        for(int b = 0; b < l; b++)
                        {
                            tmp[x + b][y + l - 1 - a] = arr[x + a][y + b];
                        }
                    }
                }
            }
            memcpy(arr, tmp, sizeof(arr));
        } else 
        {
            memcpy(tmp, arr, sizeof(arr));
        }
        
        // 주변에 얼음이 3개 이상 없으면 1씩 줄이기
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int cnt = 0;
                if(arr[i][j] == 0) continue;
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 0 || nx == n || ny < 0 || ny == n) continue;
                    if(arr[nx][ny] > 0) cnt++;
                }
                if(cnt < 3)
                {
                    tmp[i][j]--;
                }
            }
        }
        memcpy(arr, tmp, sizeof(arr));
    }

    // 남은 얼음합 세기 + dfs로 칸 개수 세기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] > 0 && !isVisited[i][j])
            {
                ans = max(ans, find(i, j));
            }
        }
    }

    printf("%d\n%d\n", sum, ans);
}
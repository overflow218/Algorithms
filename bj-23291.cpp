#include <iostream>
#include <vector>
using namespace std;

// (x,y)가 xy 직교좌표계처럼 간다고 생각할거임.
int arr[102][102] = {0};
// 인접한거끼리 물고기 수 조절할때 사용.
int tmpCount[102][102] = {0};


void gogo()
{
    printf("check ----------\n");
    for(int i = 8; i >= 0; i--)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[0][i];
    }

    int ans = 0;
    while(true)
    {
        // 4. 정리 다 되었는지 체크
        int big = -1, small = 987654321;
        for(int i = 0; i < n; i++)
        {
            big = max(big, arr[0][i]);
            small = min(small, arr[0][i]);
        }

        if(big - small <= k) break;
        ans++;
        // 1. 가장 작은 어항에 물고기를 한마리 넣어야함. 
        for(int i = 0; i < n; i++)
        {
            if(arr[0][i] == small) arr[0][i]++;
        }
            
        // 2. 어항쌓기
        // 시작하는 곳 인덱스, 한줄에 있는 블록의 개수.
        int start = 0, width = 1, height = 1;
        while(true)
        {
            for(int it = 1; it <= width; it++)
            {
                for(int i = 0; i < height; i++)
                {
                    arr[it][start + width + i] = arr[i][start + width - it];
                    arr[i][start + width - it] = 0;
                }
            }
            start += width;
            int tmp = width;
            width = height;
            height = tmp + 1;
            if(start + width + height > n) break;
        }

        // 3. 인접한 애들에 대해서 물고기 수 조절
        for(int x = 0; x < n; x++)
        {
            if(arr[0][x] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[y][x] == 0) break;
                // 오른쪽 옆에 칸 확인
                if(arr[y][x + 1] > 0)
                {
                    int diff = abs(arr[y][x] - arr[y][x + 1]) / 5;
                    if(diff > 0)
                    {
                        if(arr[y][x] < arr[y][x + 1])
                        {
                            tmpCount[y][x] += diff;
                            tmpCount[y][x + 1] -= diff;
                        } else 
                        {
                            tmpCount[y][x] -= diff;
                            tmpCount[y][x + 1] += diff;
                        }
                    }
                }
                // 위에 칸 칸 확인
                if(arr[y + 1][x] > 0)
                {
                    int diff = abs(arr[y][x] - arr[y + 1][x]) / 5;
                    if(diff > 0)
                    {
                        if(arr[y][x] < arr[y + 1][x])
                        {
                            tmpCount[y][x] += diff;
                            tmpCount[y + 1][x] -= diff;
                        } else 
                        {
                            tmpCount[y][x] -= diff;
                            tmpCount[y + 1][x] += diff;
                        }
                    }
                }
            }
        }

        // 조절내용 반영
        for(int x = 0; x < n; x++)
        {
            if(arr[0][x] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[y][x] == 0) break;
                arr[y][x] += tmpCount[y][x];
                tmpCount[y][x] = 0;
            }
        }

        // 4.다시 일렬로 놓기
        vector<int> tmp;

        for(int x = 0; x < n; x++)
        {
            if(arr[0][x] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[y][x] == 0) break;
                tmp.push_back(arr[y][x]);
                arr[y][x] = 0;
            }
        }

        for(int i = 0; i < n; i++)
        {
            arr[0][i] = tmp[i];
        }

        // 5. 지랄난 공중부양
        start = 0, width = n/2, height = 1;
        int cnt = 0;
        while(cnt < 2)
        {
            cnt++;
            for(int i = 0; i < width; i++)
            {
                for(int j = 0; j < height; j++)
                {
                    arr[2 * height - 1 - j][start + 2 * width - 1 - i] = arr[j][start + i];
                    arr[j][start + i] = 0;
                }
            }
            start += width;
            int tmp = width;
            width /= 2;
            height *= 2;
            // if(width == 1) break;
        }


        // 6. 인접한 애들에 대해서 물고기 수 조절
        for(int x = 0; x < n; x++)
        {
            if(arr[0][x] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[y][x] == 0) break;
                // 오른쪽 옆에 칸 확인
                if(arr[y][x + 1] > 0)
                {
                    int diff = abs(arr[y][x] - arr[y][x + 1]) / 5;
                    if(diff > 0)
                    {
                        if(arr[y][x] < arr[y][x + 1])
                        {
                            tmpCount[y][x] += diff;
                            tmpCount[y][x + 1] -= diff;
                        } else 
                        {
                            tmpCount[y][x] -= diff;
                            tmpCount[y][x + 1] += diff;
                        }
                    }
                }
                // 위에 칸 칸 확인
                if(arr[y + 1][x] > 0)
                {
                    int diff = abs(arr[y][x] - arr[y + 1][x]) / 5;
                    if(diff > 0)
                    {
                        if(arr[y][x] < arr[y + 1][x])
                        {
                            tmpCount[y][x] += diff;
                            tmpCount[y + 1][x] -= diff;
                        } else 
                        {
                            tmpCount[y][x] -= diff;
                            tmpCount[y + 1][x] += diff;
                        }
                    }
                }
            }
        }

        // 조절내용 반영
        for(int x = 0; x < n; x++)
        {
            if(arr[0][x] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[y][x] == 0) break;
                arr[y][x] += tmpCount[y][x];
                tmpCount[y][x] = 0;
            }
        }

        // 7.다시 일렬로 놓기
        tmp.clear();

        for(int x = 0; x < n; x++)
        {
            if(arr[0][x] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[y][x] == 0) break;
                tmp.push_back(arr[y][x]);
                arr[y][x] = 0;
            }
        }

        for(int i = 0; i < n; i++)
        {
            arr[0][i] = tmp[i];
        }
    }

    cout << ans << '\n';
    return 0;
}
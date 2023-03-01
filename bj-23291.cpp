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
            
        // gogo();
        // 2. 어항쌓기
        // 시작하는 곳 인덱스, 한줄에 있는 블록의 개수.
        int start = 0, width = 1, height = 1;
        while(true)
        {
            printf("star: %d, w: %d, h: %d\n", start, width, height);
            for(int it = 1; it <= width; it++)
            {
                for(int i = 0; i < height; i++)
                {
                    arr[start + i][it] = arr[start - it][i];
                    arr[start - it][i] = 0;
                }
            }
            start += width;
            int tmp = width;
            width = height;
            height = tmp + 1;
            // 멈춰야하는건 
            
            gogo();
            if(start + width + height > n) break;
        }

        // 3. 인접한 애들에 대해서 물고기 수 조절
        for(int x = 0; x < n; x++)
        {
            if(arr[x][0] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[x][y] == 0) break;
                // 위에 칸 확인.
                if(arr[x][y + 1] > 0)
                {
                    int diff = abs(arr[x][y] - arr[x][y + 1]) / 5;
                    if(diff > 0)
                    {
                        if(arr[x][y] < arr[x][y + 1])
                        {
                            tmpCount[x][y] += diff;
                            tmpCount[x][y + 1] -= diff;
                        } else 
                        {
                            tmpCount[x][y] -= diff;
                            tmpCount[x][y + 1] += diff;
                        }
                    }
                }
                // 오른쪽 옆에 칸 확인
                if(arr[x + 1][y] > 0)
                {
                    int diff = abs(arr[x][y] - arr[x + 1][y]) / 5;
                    if(diff > 0)
                    {
                        if(arr[x][y] < arr[x + 1][y])
                        {
                            tmpCount[x][y] += diff;
                            tmpCount[x][y + 1] -= diff;
                        } else 
                        {
                            tmpCount[x][y] -= diff;
                            tmpCount[x][y + 1] += diff;
                        }
                    }
                }
            }
        }

        // 4.다시 일렬로 놓기
        vector<int> tmp;
        for(int x = 0; x < n; x++)
        {
            if(arr[x][0] == 0) continue;
            for(int y = 0; y < n; y++)
            {
                if(arr[x][y] == 0) break;
                tmp.push_back(arr[x][y]);
                arr[x][y] = 0;
            }
        }   
        printf("tmp: %d\n", tmp.size());
        // assert(tmp.size() == n);     
        // for(int i = 0; i < n; i++)
        // {
        //     arr[i][0] = tmp[i];
        //     printf("%d ", arr[i][0]);
        // }

        break;
        // 5. 지랄난 공중부양

    }

    cout << ans << '\n';
    return 0;
}
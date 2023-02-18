#include <iostream>
#include <cstring>
using namespace std;

int arr[100][100];
// 가능하면 1, 모르면 -1, 안되면 0
int cache[100][100][2];
int n, l;

// type =0 은 가로방향, type = 1은 세로방향
int find(int x, int y, int type)
{
    if(x == n || y == n) return 1;
    int &ret = cache[x][y][type];
    if(ret != -1) return ret;

    ret = 0;
    // 가로 방향일때
    if(type == 0)
    {
        // 이전칸이 +1 높이라서 여기서부터 시작하는 내려가는 경사로가 필요한 경우
        if(y > 0 && arr[x][y - 1] == arr[x][y] + 1)
        {
            // 최소 l칸이 필요함. 
            if(y + l > n) return 0;

            for(int i = 0; i < l; i++)
            {
                if(arr[x][y] != arr[x][y + i]) return 0;
            }
            // 여기까지 왔으면 일단 경사로를 놓을수는 있음. 근데 높이가 맞는지를 체크해야함.
            int next = y + l;
            if(next == n || arr[x][next] <= arr[x][y])
            {
                ret = find(x, next, type);
            }
        } else 
        {
            // 그 외의 경우에는 옆으로 직진, 올라가는 경사로 가능한지 체크
            if(y + 1 == n || arr[x][y] == arr[x][y + 1])
            {
                ret = find(x, y + 1, type);
            }
            // 최소 l칸이 필요함. 
            if(y + l <= n)
            {
                bool isPossible = true;
                for(int i = 0; i < l; i++)
                {
                    if(arr[x][y] != arr[x][y + i])
                    {
                        isPossible = false;
                        break;
                    }
                }
                if(isPossible)
                {
                    // 여기까지 왔으면 일단 경사로를 놓을수는 있음. 근데 높이가 맞는지를 체크해야함.
                    int next = y + l;
                    if(next == n || arr[x][next] - 1 == arr[x][y])
                    {
                        ret = ret | find(x, next, type);
                    }
                }
            }
        }
    } else 
    {
        // 이전칸이 +1 높이라서 여기서부터 시작하는 내려가는 경사로가 필요한 경우
        if(x > 0 && arr[x - 1][y] == arr[x][y] + 1)
        {
            // 최소 l칸이 필요함. 
            if(x + l > n) return 0;

            for(int i = 0; i < l; i++)
            {
                if(arr[x][y] != arr[x + i][y]) return 0;
            }
            // 여기까지 왔으면 일단 경사로를 놓을수는 있음. 근데 높이가 맞는지를 체크해야함.
            int next = x + l;
            if(next == n || arr[next][y] <= arr[x][y])
            {
                ret = find(next, y, type);
            }
        } else 
        {
            // 그 외의 경우에는 옆으로 직진, 올라가는 경사로 가능한지 체크
            if(x + 1 == n || arr[x + 1][y] == arr[x][y])
            {
                ret = find(x + 1, y, type);
            }
            // 최소 l칸이 필요함. 
            if(x + l <= n)
            {
                bool isPossible = true;
                for(int i = 0; i < l; i++)
                {
                    if(arr[x][y] != arr[x + i][y])
                    {
                        isPossible = false;
                        break;
                    }
                }
                if(isPossible)
                {
                    // 여기까지 왔으면 일단 경사로를 놓을수는 있음. 근데 높이가 맞는지를 체크해야함.
                    int next = x + l;
                    if(next == n || arr[next][y] - 1 == arr[x][y])
                    {
                        ret = ret | find(next, y, type);
                    }
                }
            }
        }
    }
    return ret;
}

int main()
{
    cin >> n >> l;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(find(0, i, 1))
        {
            ans++;
            printf("세로 %d줄 가능\n", i);
        }
        if(find(i, 0, 0))
        {
            ans++;
            printf("가로 %d줄 가능\n", i);
        }
        // ans += find(0, i, 1);
        // ans += find(i, 0, 0);
    }

    cout << ans << '\n';
    return 0;
}
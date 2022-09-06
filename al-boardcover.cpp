#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c, h, w;

int board[20][20] = {0};
const int dx[4][3] = {{0, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 1, 1}};
const int dy[4][3] = {{0, -1, 0}, {0, 1, 0}, {0, 1, 1}, {0, 0, 1}};

// x,y가 상단 좌측 기준 블록일때 idx번 방법으로 덮어줌. 
// type == 1이면 덮는 거고, type == -1 이면 치우는거임.
// 올바르게 덮을 수 있으면 true, 아니면 false 반환
bool cover(int x, int y, int idx, int type)
{
    bool isPossible = true;
    for(int i = 0; i < 3; i++)
    {
        int nx = x + dx[idx][i], ny = y + dy[idx][i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w)
        {
            isPossible = false;
        } else if((board[nx][ny] += type) > 1)
        {
            isPossible = false;
        }
    }
    return isPossible;
}


int find(int x, int y, int count)
{
    // 다 채운 경우
    if(count == 0)
    {
        return 1;
    }

    // 덮힌 칸인 경우 -> 다음으로 넘어감
    if(board[x][y])
    {
        if(y == w - 1)
        {
            return find(x + 1, 0, count);
        }
        return find(x, y + 1, count);
    }

    // 안 덮힌 칸인 경우 덮어주고 넘어감 
    int sum = 0;
    for(int i = 0; i < 4; i++)
    {
        bool isPossible = cover(x, y, i, 1);
        if(isPossible)
        {
            if(y == w - 1)
            {
                sum += find(x + 1, 0, count - 3);
            } else 
            {
                sum += find(x, y + 1, count - 3);
            }
        }
        // 덮은거 다시 치워주기
        cover(x, y, i, -1);
    }

    // 못 덮는 칸인 경우 위의 포문에서 다음 재귀호출이 일어나지 않기때문에 여기서 0반환하고 끝남.
    return sum;
}

int main()
{
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d %d", &h, &w);
        memset(board, 0, sizeof(board));
        char buf[21] = {0};
        int cnt = 0;
        for(int i = 0; i < h; i++)
        {
            scanf("%s", buf);
            for(int j = 0; j < w; j++)
            {
                board[i][j] = buf[j] == '#' ? 1 : 0;
                cnt += '.' == buf[j];
            }
        }
        if(cnt % 3)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", find(0, 0, cnt));
    }
    return 0;
}
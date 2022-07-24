#include <cstdio>
using namespace std;
int ans[2] = {0, 0};
int board[128][128] = {0};

void check(int x, int y, int size)
{
    bool isSame = true;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(board[x + i][y + j] != board[x][y])
            {
                isSame = false;
                break;
            }
        }
        if(!isSame)
        {
            break;
        }
    }
    if(isSame)
    {
        ans[board[x][y]]++;
    } else 
    {
        check(x, y, size / 2);
        check(x + size/2, y, size / 2);
        check(x, y + size/2, size / 2);
        check(x + size/2, y + size/2, size / 2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    check(0, 0, n);
    printf("%d\n%d", ans[0], ans[1]);
}
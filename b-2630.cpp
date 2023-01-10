#include <iostream>

int board[128][128];
int color[2] = {0, 0};
int white = 0, blue = 0;

void find(int x, int y, int size)
{
    bool allSame = true;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(board[x][y] != board[x + i][y + j])
            {
                allSame = false;
                break;
            }
            if(!allSame) break;
        }
    }
    if(allSame)
    {
        color[board[x][y]]++;
        return;
    }
    find(x, y, size / 2);
    find(x + size / 2, y, size / 2);
    find(x, y + size / 2, size / 2);
    find(x + size / 2, y + size / 2, size / 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    find(0, 0, n);
    printf("%d\n%d\n", color[0], color[1]);
    return 0;
}
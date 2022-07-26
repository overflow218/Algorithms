#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int dx[] = {1, 1, 2, 2};
int dy[] = {1, 2, 1, 2};

int fun(int x, int y, int targetX, int targetY, int size, int cnt)
{
    if(size == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            if(x + (dx[i] - 1) == targetX && y + (dy[i] - 1) == targetY)
            {
                return cnt + i;
            }
        }
    } else 
    {
        for(int i = 0; i < 4; i++)
        {
            if(targetX < x + dx[i] * size && targetY < y + dy[i] * size)
            {
                return fun(x + (dx[i] - 1) * size, y + (dy[i] - 1) * size, targetX, targetY, size / 2, cnt + size * size * i);
            }
        }
    }
    return 0;
}

int main()
{
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    printf("%d\n", fun(0, 0, r, c, (int) pow(2, n - 1), 0));
    return 0;
}
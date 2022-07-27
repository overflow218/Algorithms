#include <iostream>
#include <cstdio>
using namespace std;

char arr[64][65] = {0};

void fun(int x, int y, int size)
{
    if(size == 1)
    {
        printf("%c", arr[x][y]);
    } else 
    {
        bool isSame = true;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(arr[x + i][y + j] != arr[x][y])
                {
                    isSame = false;
                    break;
                }
            }
            if(!isSame) break;
        }
        if(isSame)
        {
            printf("%c", arr[x][y]);
        } else 
        {
            printf("(");
            fun(x, y, size / 2);
            fun(x, y + size / 2, size / 2);
            fun(x + size / 2, y, size / 2);
            fun(x + size / 2, y + size / 2, size / 2);
            printf(")");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    fun(0, 0, n);
    return 0;
}
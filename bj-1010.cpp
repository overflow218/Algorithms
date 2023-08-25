#include <iostream>
using namespace std;

int bino[31][31] = {0};

int main()
{
    int n, m, t;
    scanf("%d", &t);

    // init
    for(int i = 0; i <= 30; i++)
    {
        for(int j = 0; j <= 30; j++)
        {
            if(j == 0 || j == i)
            {
                bino[i][j] = 1;
                continue;
            }
            if(j == 1)
            {
                bino[i][1] = i;
                continue;
            }
            bino[i][j] = bino[i - 1][j] + bino[i - 1][j - 1];
        }
    }

    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", bino[m][n]); 
    }
    return 0;
}
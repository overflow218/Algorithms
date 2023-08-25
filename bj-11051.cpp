#include <iostream>
using namespace std;

int bino[1001][1001] = {0};

int main()
{
    int n, k;
    const int MOD = 10007;
    scanf("%d %d", &n, &k);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
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
            bino[i][j] = (bino[i - 1][j] + bino[i - 1][j - 1]) % MOD;
        }
    }

    printf("%d\n", bino[n][k]);
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int tri[500][500] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            scanf("%d", &tri[i][j]);
        }
    }    

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            tri[i][j] = j == 0 ? tri[i - 1][j] + tri[i][j] : j == i ? tri[i - 1][j - 1] + tri[i][j] : max(tri[i - 1][j - 1], tri[i - 1][j]) + tri[i][j];
        }
    }

    int tmp = 0;
    for(int i = 0; i < n; i++)
    {
        tmp = max(tmp, tri[n - 1][i]);
    }
    printf("%d\n", tmp);
    return 0;
}
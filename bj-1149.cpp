#include <iostream>
#include <cstdio>
using namespace std;

int color[3][1000] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &color[0][i], &color[1][i], &color[2][i]);
    }
    for(int i = 1; i < n; i++)
    {
        color[0][i] += min(color[1][i - 1], color[2][i - 1]);
        color[1][i] += min(color[0][i - 1], color[2][i - 1]);
        color[2][i] += min(color[0][i - 1], color[1][i - 1]);
    }
    printf("%d\n", min(color[0][n - 1], min(color[1][n - 1], color[2][n - 1])));
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s1[1001] = {0};
char s2[1001] = {0};

int ans[1001][1001] = {0};

int main()
{
    scanf("%s %s", s1, s2);
    int n = strlen(s1), m = strlen(s2);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ans[i][j] = s1[i - 1] == s2[j - 1] ? ans[i-1][j-1] + 1 : max(ans[i-1][j], ans[i][j-1]);
        }
    }
    printf("%d\n", ans[n][m]);
    return 0;
}
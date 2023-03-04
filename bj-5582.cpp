#include <iostream>
#include <cstring>
using namespace std;

char s1[4010];
char s2[4010];

int cache[4010][4010] = {0};
int main()
{
    scanf("%s %s", s1, s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    int ans = 0;
    for(int i = 0; i < len1; i++)
    {
        if(s1[i] == s2[0])
        {
            cache[i][0] = 1;
            ans = 1;
        }
    }

    for(int i = 0; i < len2; i++)
    {
        if(s2[i] == s1[0])
        {
            cache[0][i] = 1;
            ans = 1;
        }
    }

    for(int i = 1; i < len1; i++)
    {
        for(int j = 1; j < len2; j++)
        {
            if(s1[i] == s2[j])
            {
                cache[i][j] = cache[i - 1][j - 1] + 1;
                ans = max(ans, cache[i][j]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
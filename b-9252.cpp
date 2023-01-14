#include <iostream>
#include <cstring>
using namespace std;

char s1[1001] = {0};
char s2[1001] = {0};
int cache[1000][1000] = {0};
string ans = "";
void find(int x, int y)
{
    if(s1[x] == s2[y])
    {
        ans = s1[x] + ans;
        if(cache[x][y] == 1) return;
        return find(x - 1, y - 1);
    }
    if(x == 0 || cache[x-1][y] <= cache[x][y - 1])
    {
        return find(x, y -1);
    }
    if(y == 0 || cache[x-1][y] >= cache[x][y - 1])
    {
        return find(x - 1, y);
    }
}
int main()
{
    scanf("%s %s", s1, s2);
    int tmp = 0;
    for(int i = 0; i < strlen(s1); i++)
    {
        if(s1[i] == s2[0]) tmp = 1;
        cache[i][0] = tmp;
    }

    tmp = 0;
    for(int i = 0; i < strlen(s2); i++)
    {
        if(s1[0] == s2[i]) tmp = 1;
        cache[0][i] = tmp;
    }

    for(int i = 1; i < strlen(s1); i++)
    {
        for(int j = 1; j < strlen(s2); j++)
        {
            if(s1[i] == s2[j])
            {
                cache[i][j] = cache[i - 1][j - 1] + 1;
            } else 
            {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }

    printf("%d\n", cache[strlen(s1) - 1][strlen(s2) - 1]);
    if(cache[strlen(s1) - 1][strlen(s2) - 1] != 0)
    {
        find(strlen(s1) - 1, strlen(s2) - 1);
        printf("%s\n", ans.c_str());
    }
    return 0;
}
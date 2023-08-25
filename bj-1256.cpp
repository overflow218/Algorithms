#include <iostream>
using namespace std;

int bino[201][201] = {0};
string ans = "";

void find(int n, int m, int k)
{
    if(n == 0 && m == 0) return;
    if(n == 0)
    {
        ans += "z";
        return find(n, m - 1, k);
    }
    if(m == 0)
    {
        ans += "a";
        return find(n - 1, m, k);
    }

    int left = bino[n + m - 1][m];
    if(k <= left)
    {
        ans += "a";
        return find(n - 1, m, k);
    }

    ans += "z";
    return find(n, m - 1, k - left);
}

int main()
{
    int n, m, k, big = 0;
    
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i <= n + m; i++)
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
            bino[i][j] = bino[i - 1][j] + bino[i - 1][j - 1];
            big = max(big, bino[i][j]);
        }
    }

    if(k > big)
    {
        printf("-1\n");
        return 0;
    }

    find(n, m, k);
    printf("%s\n", ans.c_str());
    return 0;
}
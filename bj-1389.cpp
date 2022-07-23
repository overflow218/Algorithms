#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
int bacon[101][101] = {0};
bool isVisited[101][101] = {0};

int check(int start, int end)
{
    if(start == end) return 0;
    if(bacon[start][end] != 0) return bacon[start][end];
    int ans = 200;
    for (int i = 1; i <= n; i++)
    {
        if(bacon[start][i] && !isVisited[start][i])
        {
            isVisited[start][i] = true;
            ans = min(ans, check(i, end) + bacon[start][i]);
            isVisited[start][i] = false;
        }
    }
    bacon[end][start] = ans;
    return bacon[start][end] = ans;
}

int main()
{
    int from, to;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &from, &to);
        bacon[from][to] = 1;
        bacon[to][from] = 1;
    }

    int ans = 0, steps = 987654321;
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for(int j = 1; j <= n; j++)
        {
            tmp += check(i, j);
        }
        if(tmp < steps)
        {
            steps = tmp;
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
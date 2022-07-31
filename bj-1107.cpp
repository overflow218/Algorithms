#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool broken[10] = {0};
vector<int> working;
int n, m, tmp, ans;

void go(int sum, int cnt)
{
    ans = min(ans, cnt + abs(n - sum));
    if(sum >= n || sum == 0) return;
    for(auto x: working)
    {
        go(sum * 10 + x, cnt + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        broken[tmp] = true;
    }
    for(int i = 0; i < 10; i++)
    {
        if(!broken[i])
        {
            working.push_back(i);
        }
    }
    ans = abs(n - 100);
    for(auto x: working)
    {
        go(x, 1);
    }

    printf("%d\n", ans);
    return 0;
}
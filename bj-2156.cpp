#include <iostream>
#include <cstring>
using namespace std;

int n;
// dp[i] = i번부터 처음 와인마신다고 할떄 마실수있는 최대 와인량
int grape[10000] = {0};
int dp[10000] = {0};
int find(int idx)
{
    if(idx >= n) return 0;
    if(idx == n - 1) return grape[n - 1];
    int &ret = dp[idx];
    if(ret != -1) return ret;

    ret = max(find(idx + 1), grape[idx] + grape[idx + 1] + find(idx + 3));
    ret = max(ret, grape[idx] + find(idx + 2));
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> grape[i];
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", find(0));
    // for(int i = 0; i < n; i++)
    // {
    //     printf("dp[%d]: %d\n", i, dp[i]);
    // }
    return 0;
}
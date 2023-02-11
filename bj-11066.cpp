#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[501] = {0};
int pSum[501] = {0};
int dp[501][501] = {0};

int find(int start, int end)
{
    if(start == end) return 0;
    int & ret = dp[start][end];
    if(ret != 0) return ret;

    ret = 987654321;
    for(int k = start; k < end; k++)
    {
        ret = min(find(start, k) + find(k + 1, end) + pSum[end] - pSum[start - 1], ret);
    }
    return ret;
}

int main()
{
    int t, k, tmp;
    cin >> t;

    for(int it = 0; it < t; it++)
    {
        cin >> k;
        for(int i = 1; i <= k; i++)
        {
            cin >> arr[i];
            pSum[i] = pSum[i - 1] + arr[i];
        }

        memset(dp, 0, sizeof(dp));
        int ans = find(1, k);
        cout << ans << '\n';
    }
    return 0;
}

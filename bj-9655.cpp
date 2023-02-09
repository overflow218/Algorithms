#include <iostream>
#include <vector>
// #include <cstring>
using namespace std;

int n;

// idx번에서 시작하는애가 이기면 참, 아니면 거짓. 
bool win(int idx, vector<int> &dp)
{
    if(idx == n || idx == n - 2) return true;
    if(dp[idx] != -1) return dp[idx] == 1;

    bool otherWin = win(idx + 1, dp) | win(idx + 3, dp);
    if(otherWin)
    {
        dp[idx] = 0;
        return false;
    }
    dp[idx] = 1;
    return true;
}
int main()
{
    cin >> n;
    vector<int> dp(n + 1, -1);
    if(win(1, dp))
    {
        cout << "SK\n";
    } else 
    {
        cout << "CY\n";
    }
    return 0;
}
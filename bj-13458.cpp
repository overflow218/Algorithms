#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, major, minor;
    cin >> n;
    long long ans = n;
    vector<int> classRoom(n);
    for(int i = 0; i < n; i++)
    {
        cin >> classRoom[i];
    }

    cin >> major >> minor;
    for(int i = 0; i < n; i++)
    {
        int tmp = classRoom[i] - major;
        if(tmp <= 0) continue;;
        long long cnt = (tmp + minor - 1) / minor;
        ans += cnt;
    }

    cout << ans << '\n';
    return 0;
}
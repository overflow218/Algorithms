#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s, e;
    cin >> n;
    vector<pair<int, int>> line(n + 1);
    for(int i = 0; i < n; i++)
    {
        cin >> s >> e;
        line[i] = make_pair(s, e);
    }
    line[n] = make_pair(1000000001, 1000000001);
    sort(line.begin(), line.end());
    int ans = 0;
    s = line[0].first; e = line[0].second;

    for(const auto &check: line)
    {
        int nStart = check.first, nEnd = check.second;
        if(nStart <= e)
        {
            e = max(e, nEnd);
        } else 
        {
            ans += e - s;
            s = nStart; e = nEnd;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
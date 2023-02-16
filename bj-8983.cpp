#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, l, x, y, ans = 0;
    cin >> m >> n >> l;
    vector<pair<int, int>> animals(n);
    vector<int> shot(m);

    for(int i = 0; i < m; i++)
    {
        cin >> shot[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        animals[i] = make_pair(x, y);
    }
   sort(shot.begin(), shot.end());

    for(const auto& animal:animals)
    {
        x = animal.first, y = animal.second;
        int idx = lower_bound(shot.begin(), shot.end(), x) - shot.begin();
        if(idx < m)
        {
            int dist = shot[idx] - x + y;
            if(dist <= l)
            {
                ans++;
                continue;
            }
        }
        if(idx > 0)
        {
            int dist = x - shot[idx - 1] + y;
            if(dist <= l) ans++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
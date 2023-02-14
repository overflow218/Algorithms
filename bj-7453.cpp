#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a(4000, 0), b(4000, 0), c(4000, 0), d(4000,0), ab, cd;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long ans = 0;
    int idx1 = 0;
    while(idx1 < ab.size())
    {
        int x = ab[idx1];
        int it = lower_bound(cd.begin(), cd.end(), -x) - cd.begin();
        int cnt1 = 1, cnt2 = 1;
        if(it < cd.size() && cd[it] == -x)
        {
            for(int i = it + 1; i < cd.size(); i++)
            {
                if(cd[i] != -x) break;
                cnt2++;
            }
            for(int i = idx1 + 1; i < ab.size(); i++)
            {
                if(ab[i] != x) break;
                cnt1++;
            }
            ans += (long long) cnt1 * (long long)cnt2;
        }
        idx1 += cnt1;
    }
    
    cout << ans << '\n';
    return 0;
}
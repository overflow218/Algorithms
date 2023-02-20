#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<int, int>> check;
    for(int i = 0; i < n; i++)
    {
        check.push_back(make_pair(b[i], a[i]));
    }

    sort(check.begin(), check.end());

    vector<vector<long long>> giftcon;
    int prev = 0;
    for(int i = 0; i < n; i++)
    {
        int a = check[i].second, b = check[i].first;
        int add = 0;
        if(a < b)
        {
            add = (b - a + 29) / 30;
            a += add * 30;
            ans += add;
        }
        if(b != prev)
        {
            vector<long long> newDay = {(long long) a};
            giftcon.push_back(newDay);
            prev = b;
        } else 
        {
            giftcon.back().push_back(a);
        }
    }

    long long minimum = 0;
    for(auto & cons:giftcon)
    {
        long long tmpMinimum = minimum;
        for(auto &con: cons)
        {
            tmpMinimum = max(tmpMinimum, con);
            if(minimum > con)
            {
                long long tmp = (minimum - con + 29ll) / 30ll;
                ans += tmp;
                tmpMinimum = max(tmpMinimum, con + 30 * tmp);
            }
        }
        minimum = tmpMinimum;
    }

    cout << ans << '\n';
    return 0;
}
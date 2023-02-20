#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, l, from, to;
    cin >> n >> l;

    vector<pair<int, int>> check(n);
    for(int i = 0; i < n; i++)
    {
        cin >> from >> to;
        check[i] = make_pair(from, to);
    }
    sort(check.begin(), check.end());

    int last = 0, ans = 0;
    for(auto & ho:check)
    {
        from = ho.first; to = ho.second;
        last = max(last, from);
        if(last < to)
        {
            int add = (to - last + l - 1) / l;
            ans += add;
            last += add * l;
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int x, y, w, s;
    cin >> x >> y >> w >> s;

    long long ans = 0;
    if(2 * w <= s)
    {
        ans = (long long)(x + y) * w;
    } else 
    {
        ans += (long long)min(x, y) * s;
        long long left = max(x, y) - min(x,y);
        if(left % 2 == 1)
        {
            ans += (long long)w;
            left--;
        }
        ans += left * min(s, w);
    }
    cout << ans <<'\n';
    return 0;
}
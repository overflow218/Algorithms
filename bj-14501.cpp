#include <iostream>
#include <cstring>
using namespace std;

int n, t[15], pay[15], cache[15];

int find(int idx)
{
    if(idx == n) return 0;
    int &ret = cache[idx];
    if(ret != -1) return ret;

    ret = find(idx + 1);
    if(idx + t[idx] <= n)
    {
        ret = max(ret, pay[idx] + find(idx + t[idx]));
    }
    return ret;
}
int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));

    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        cin >> pay[i];
    }

    cout << find(0) << '\n';
    return 0;
}
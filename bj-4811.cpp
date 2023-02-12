#include <iostream>
#include <cstring>
using namespace std;

long long cache[31][31];
long long find(int w, int h)
{
    if(w == 0 && h == 0) return 1;
    long long &ret = cache[w][h];
    if(ret != -1) return ret;
    ret = 0ll;
    if(w > 0) ret += find(w - 1, h + 1);
    if(h > 0) ret += find(w, h - 1);
    return ret;
}
int main()
{
    int tmp;
    memset(cache, -1, sizeof(cache));
    find(30, 0);
    while(true)
    {
        cin >> tmp;
        if(tmp == 0) break;
        cout << find(tmp, 0) << '\n';
    }
    return 0;
}
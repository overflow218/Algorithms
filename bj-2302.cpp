#include <iostream>
using namespace std;

int n, m, tmp;
int cache[50] = {0};
bool isVip[50] = {false};

int find(int idx)
{
    if(idx > n) return 1;
    int &ret = cache[idx];
    if(ret != 0) return ret;
    
    ret = find(idx + 1);
    if(!isVip[idx] && idx + 1 <= n && !isVip[idx + 1])
    {
        ret += find(idx + 2);
    }
    return ret;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        isVip[tmp] = true;
    }

    cout << find(1) << '\n';
    return 0;
}
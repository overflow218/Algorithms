#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> gate;
int main()
{
    int g, p, tmp, ans = 0;
    scanf("%d %d", &g, &p);
    bool isDone = false;
    for(int i = 1; i <= g; i++)
    {
        gate.insert(-i);
    }
    for(int i = 0; i < p; i++)
    {
        scanf("%d", &tmp);
        if(isDone) continue;
        auto it = gate.lower_bound(-tmp);
        if(it == gate.end()) {
            isDone = true;
            continue;
        }
        ans++;
        gate.erase(it);
    }
    printf("%d\n", ans);
    return 0;
}
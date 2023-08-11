#include <iostream>
#include <set>
using namespace std;

set<int> s;
int main()
{
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        s.insert(tmp);
        auto h = s.find(tmp);
        int idx = s.find(tmp) - s.begin();
        auto idx = s.find(tmp) - s.begin();
        int idx = s.end() - s.begin();
        printf("%d\n", s.size() - idx);
    }

    return 0;
}
#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
int main()
{
    int n, tmp;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
        int idx = i / 2;
        printf("%d\n", *(s.begin() + idx));
    }
    return 0;
}
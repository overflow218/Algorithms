#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
void go(int x, vector<int> & chosen)
{
    if(x == n + 1 && chosen.size() < m) return;
    if(chosen.size() == m)
    {
        for(int i = 0; i < m; i++)
        {
            printf("%d ", chosen[i]);
        }
        printf("\n");
    } else 
    {
        for(int i = x; i <= n; i++)
        {
            chosen.push_back(i);
            go(i, chosen);
            chosen.pop_back();
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    vector<int> vec;
    go(1, vec);
    return 0;
}
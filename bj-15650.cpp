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
        chosen.push_back(x);
        go(x + 1, chosen);
        chosen.pop_back();
        go(x + 1, chosen);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    vector<int> vec;
    go(1, vec);
    return 0;
}
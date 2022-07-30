#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> input;

void go(int x, vector<int> & chosen)
{
    if(chosen.size() == m)
    {
        for(int i = 0; i < m; i++)
        {
            printf("%d ", input[chosen[i]]);
        }
        printf("\n");
    } else 
    {
        for(int i = x; i < n; i++)
        {
            chosen.push_back(i);
            go(i, chosen);
            chosen.pop_back();
        }
    }
}

int main()
{
    int tmp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());
    
    vector<int> vec;
    go(0, vec);
    return 0;
}
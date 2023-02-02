#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, capacity, m, weight;
    scanf("%d", &n);
    vector<int> crain(n, 0);
    multiset<int> box;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &capacity);
        crain[i] = -capacity;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &weight);
        box.insert(-weight);
    }

    int time = 0;
    while(!box.empty())
    {
        bool isImpossible = true;
        for(int i = 0; i < n; i++)
        {
            auto it = box.lower_bound(crain[i]);
            if(it != box.end())
            {
                isImpossible = false;
                box.erase(it);
            }
        }
        if(isImpossible)
        {
            time = -1;
            break;
        }
        time++;
    }

    printf("%d\n", time);
    return 0;
}
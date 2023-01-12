#include <iostream>
#include <vector>
using namespace std;

int build(int idx, vector<vector<int>>& preRequired, vector<int> & cost, vector<int> &cache)
{
    int &ret = cache[idx];
    if(ret != 0) return ret;
    
    for(int i = 0; i < preRequired[idx].size(); i++)
    {
        ret = max(ret, build(preRequired[idx][i], preRequired, cost, cache));
    }
    return ret = ret + cost[idx];
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> preRequired(n + 1);
    vector<int> cost(n + 1);
    vector<int> cache(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &cost[i]);
        scanf("%d", &tmp);
        while(tmp != -1)
        {
            preRequired[i].push_back(tmp);
            scanf("%d", &tmp);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        printf("%d\n", build(i, preRequired, cost, cache));
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int build(int idx, vector<vector<int>> &preBuild, vector<int> &cost, vector<int> &D)
{
    int &ret = cost[idx];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < preBuild[idx].size(); i++)
    {
        ret = max(ret, build(preBuild[idx][i], preBuild,cost, D));
    }
    return ret = ret + D[idx];
}

int main()
{
    int t, n, k, x, y, d, goal;
    scanf("%d", &t);
    for(int h = 0; h < t; h++)
    {
        scanf("%d %d", &n, &k);
        vector<int> D(n + 1);
        vector<int> cost(n + 1, -1);
        vector<vector<int>> preBuild(n + 1);

        D[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &D[i]);
        }
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);
            preBuild[y].push_back(x);
        }
        scanf("%d", &goal);
        printf("%d\n", build(goal, preBuild, cost, D));
    }
    return 0;
}
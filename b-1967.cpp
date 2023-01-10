#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<pair<int, int>>> edge;
int ans = 0;

int find(int current)
{
    int max1 = 0, max2 = 0;
    for(int i = 0; i < edge[current].size(); i++)
    {
        int tmp = find(edge[current][i].first) + edge[current][i].second;
        if(tmp > max1)
        {
            max2 = max1;
            max1 = tmp;
        } else if(tmp > max2)
        {
            max2 = tmp;
        }
    }
    ans = max(ans, max1 + max2);
    return max1;
}
int main()
{
    int n, parent, child, w;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        vector<pair<int, int>> tmp;
        edge[i] = tmp;
    }

    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d", &parent, &child, &w);
        edge[parent].push_back(make_pair(child, w));
    }
    find(1);

    printf("%d\n", ans);
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> edge;

void find(int from, int current, vector<int>&parent)
{
    if(parent[current] != 0) return;
    parent[current] = from;
    for(int i = 0; i < edge[current].size(); i++)
    {
        find(current, edge[current][i], parent);
    }
}

int main()
{
    int n, a, b;
    scanf("%d", &n);
    vector<int> parent (n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        vector<int> tmp;
        edge[i] = tmp;
    }
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    find(1, 1, parent);

    for(int i = 2; i <= n; i++)
    {
        printf("%d\n", parent[i]);
    }
    return 0;
}
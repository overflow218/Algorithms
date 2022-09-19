#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int cache[100][100001];
int n, k, w, v;
vector<pair<int, int>> items;

int find(int idx, int capacity)
{
    if(idx == n) return 0;
    int &ret = cache[idx][capacity];
    if(ret != -1) return ret;
    if(capacity >= items[idx].first){
        ret = find(idx + 1, capacity - items[idx].first) + items[idx].second;
    }
    return ret = max(ret, find(idx + 1, capacity));
}

int main()
{
    scanf("%d %d", &n, &k);
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &w, &v);
        items.push_back(make_pair(w, v));
    }
    printf("%d\n", find(0, k));
    return 0;
}
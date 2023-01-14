#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

multiset<int> bag;
int main()
{
    int n, k, m, v, c;
    scanf("%d %d", &n, &k);

    // (가치, 무게)
    vector<pair<int, int>> gold;

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &m, &v);
        gold.push_back(make_pair(v, m));
    }
    sort(gold.begin(), gold.end(), greater<pair<int, int>>());

    for(int i = 0; i < k; i++)
    {
        scanf("%d", &c);
        bag.insert(c);
    }

    long long ans = 0, cnt = k;

    for(int i = 0; i < n; i++)
    {
        int value = gold[i].first, weight = gold[i].second;
    }
    for(int i = 0; i < n; i++)
    {
        if(cnt == 0) break;
        int value = gold[i].first, weight = gold[i].second;
        multiset<int> :: iterator it = bag.lower_bound(weight);
        if(it != bag.end())
        {
            ans += (long long)value;
            cnt--;
            bag.erase(it);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, tmp;
    vector<pair<int, int>> house;
    vector<pair<int, int>> chicken;
    vector<vector<int>> distance;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &tmp);
            if(tmp == 1)
            {
                house.push_back(make_pair(i, j));
            } else if(tmp == 2)
            {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < house.size(); i++)
    {
        vector<int> tmp_distance;
        for(int j = 0; j < chicken.size(); j++)
        {
            int tmp = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
            tmp_distance.push_back(tmp);
        }
        distance.push_back(tmp_distance);
    }

    int ans = 987654321;
    for(int t = 1; t <= m; t++)
    {
        vector<bool> check(chicken.size(), false);
        for(int i = 0; i < t; i++)
        {
            check[i] = true;
        }
        int cnt = 0;
        do {
            int sum = 0;
            for(int i = 0; i < house.size(); i++)
            {
                int tmp = 987654321;
                for(int j = 0; j < check.size(); j++)
                {
                    if(check[j])
                    {
                        tmp = min(tmp, distance[i][j]);
                    }
                }
                sum += tmp;
            }
            ans = min(ans, sum);
        } while(prev_permutation(check.begin(), check.end()));
    }

    printf("%d\n", ans);
    return 0;
}
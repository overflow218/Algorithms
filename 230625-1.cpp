#include <cstring>
class Solution {
public:
    int cache[100][201];
    const int MOD = 1000000007;
    int find(int idx, int fuel, int finish, vector<int>& locations)
    {
        if(fuel == 0) return idx == finish ? 1 : 0;
        int &ret = cache[idx][fuel];
        if(ret != -1) return ret;
        ret = idx == finish ? 1 : 0;
        for(int i = 0; i < locations.size(); i++)
        {
            int diff = abs(locations[idx] - locations[i]);
            if(i == idx || diff > fuel) continue;
            ret = (ret + find(i, fuel - diff, finish, locations)) % MOD;
        }
        return ret;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(cache, -1, sizeof(cache));
        return find(start, fuel, finish, locations);
    }
};
#include <algorithm>
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long cnt = mass;
        sort(asteroids.begin(), asteroids.end());
        for(const int & num:asteroids)
        {
            if(num > cnt) return false;
            cnt += (long long)num;
        }
        return true;
    }
};
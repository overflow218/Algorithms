#include <cstring>

class Solution {
public:
    int cache[100][100];
    int find(int x, int y, int m, int n)
    {
        if(x == m || y == n) return 0;
        if(x == m - 1 && y == n - 1) return 1;
        int &ret = cache[x][y];
        if(ret != -1) return ret;
        ret = find(x + 1, y, m, n) + find(x, y + 1, m, n);
        return ret;
    }

    int uniquePaths(int m, int n) {
        memset(cache, -1, sizeof(cache));
        return find(0, 0, m, n);
    }
};
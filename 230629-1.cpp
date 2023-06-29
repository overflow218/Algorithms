#include <cctype>
#include <cstring>
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n, k = 0;
    int block[30][30][64] = {0};
    const int INF = 10000;
    int find(int x, int y, int key, vector<string>& grid)
    {
        if(x < 0 || x == m || y < 0 || y == n) return INF;
        if(grid[x][y] == '#') return INF;
        int &ret = block[x][y][key];
        if(ret != -1) return ret;
        ret = INF;
        // lock을 만났는데, 키가 없을때
        if(isupper(grid[x][y]))
        {
            int idx = grid[x][y] - 'A';
            if(!(key & (1 << idx))) return ret = INF;
        }
        // key를 얻었을때
        if(islower(grid[x][y]))
        {
            int idx = grid[x][y] - 'a';
            key |= (1 << idx);
            int check = (1 << k) - 1;
            if(key == check) return ret = 0;
        }

        for(int i = 0; i < 4; i++)
        {
            ret = min (ret , 1 + find(x + dx[i], y + dy[i], key, grid));
        }
        return ret;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(block, -1, sizeof(block));
        int sX, sY;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isupper(grid[i][j])) k++;
                if(grid[i][j] == '@')
                {
                    sX = i; sY = j;
                }
            }
        }
        int ans = find(sX, sY, 0, grid);
        return ans == INF ? -1 : ans;
    }
};
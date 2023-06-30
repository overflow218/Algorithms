#include <cctype>
#include <cstring>
#include <queue>
class Solution {
public:
    struct ho {
        int x;
        int y;
        int key;
    };
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int block[30][30][64];
   
    queue<ho> q;
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k = 0;
        memset(block, -1, sizeof(block));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isupper(grid[i][j])) k++;
                if(grid[i][j] == '@') q.push(ho{i, j, 0});
            }
        }

        int cnt = 0;
        while(!q.empty())
        {
            int limit = q.size();
            for(int i = 0; i < limit; i++)
            {
                struct ho tmp = q.front();
                q.pop();
                int x = tmp.x, y = tmp.y, key = tmp.key;
                if(x < 0 || x == m || y < 0 || y == n) continue;
                if(grid[x][y] == '#') continue;
                if(block[x][y][key] != -1) continue;
                block[x][y][key] = cnt;
                // lock을 만났는데, 키가 없을때
                if(isupper(grid[x][y]))
                {
                    int idx = grid[x][y] - 'A';
                    if(!(key & (1 << idx))) continue;
                }
                // key를 얻었을때
                if(islower(grid[x][y]))
                {
                    int idx = grid[x][y] - 'a';
                    key |= (1 << idx);
                    int check = (1 << k) - 1;
                    if(key == check) return cnt;
                }

                for(int j = 0; j < 4; j++)
                {
                    q.push(ho{x + dx[j],y + dy[j], key});
                }
            }
            cnt++;
        }
        return -1;
    }
};
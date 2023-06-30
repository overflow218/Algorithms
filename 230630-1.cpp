#include <queue>
#include <cstring>
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int s = 0, e = cells.size() - 1, ans = 0;
        vector<vector<bool>> isVisited = vector<vector<bool>>(row, vector<bool>(col));
        vector<vector<bool>> isBlocked = vector<vector<bool>>(row, vector<bool>(col));
        while(s <= e)
        {
            int mid = (s + e) / 2;
            isVisited = vector<vector<bool>>(row, vector<bool>(col, false));
            isBlocked = vector<vector<bool>>(row, vector<bool>(col, false));
            for(int i = 0; i <= mid; i++)
            {
                isBlocked[cells[i][0] - 1][cells[i][1] - 1] = true;
            }

            q = queue<pair<int, int>>();
            for(int i = 0; i < col; i++)
            {
                q.push(make_pair(0, i));
            }

            bool isPossible = false;
            while(!q.empty())
            {
                pair<int, int> tmp = q.front();
                q.pop();
                int x = tmp.first, y = tmp.second;
                if(x < 0 || x == row || y < 0 || y == col) continue;
                if(isVisited[x][y] || isBlocked[x][y]) continue;
                isVisited[x][y] = true;
                if(x == row - 1)
                {
                    isPossible = true;
                    break;
                }
                for(int i = 0; i < 4; i++)
                {
                    q.push(make_pair(x + dx[i], y + dy[i]));
                }
            }

            // 끝까지 도달 가능
            if(isPossible)
            {
                ans = max(ans, mid);
                s = mid + 1;
            }
            // 끝까지 도달 안될때
            else 
            {
                e = mid - 1;
            }
        }
        
        return ans + 1;
    }
};
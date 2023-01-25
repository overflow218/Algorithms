#include <queue>
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> check(n * n + 1, 0);
        vector<bool> isVisited(n * n + 1, false);
        int cnt = 1;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i % 2)
                {
                    check[cnt++] = board[n - 1 - i][n - 1 - j];
                } else 
                {
                    check[cnt++] = board[n - 1 - i][j];
                }
            }
        }

        q.push(make_pair(1, 0));
        while(!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            int cur = tmp.first, cnt = tmp.second;
            if(cur == n * n) return cnt;
            if(isVisited[cur]) continue;
            isVisited[cur] = true;
            for(int i = 1; i <= 6; i++)
            {
                int next = min(n * n , cur + i);
                if(check[next] != -1)
                {
                    next = check[next];
                }
                q.push(make_pair(next, cnt + 1));
            }

        }
        return -1;
    }
};
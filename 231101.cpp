# leetcode 529번
class Solution {
public:
    int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
    int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
    int m, n;
    bool isVisited[50][50] = {false};
    void visit(int x, int y, vector<vector<char>>& board)
    {
        if(x < 0 || x == m || y < 0 || y == n) return;
        if(isVisited[x][y]) return;
        isVisited[x][y]= true;

        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
        }
        if(board[x][y] == 'E')
        {
            int cnt = 0;
            for(int i = 0; i < 8; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
                if(board[nx][ny] == 'X') cnt++;
            }
            if(cnt > 0)
            {
                board[x][y] = cnt;
                return;
            }
            board[x][y] = 'B';
            for(int i = 0; i < 8; i++)
            {
                visit(x + dx[i], y + dy[i], board);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {   
       m = board.size();
       n = board[0].size();
       visit(click[0], click[1], board);
       return board;
    }
};

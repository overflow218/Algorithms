#include <cstring>

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int find(int x, int y, int idx, vector<vector<char>>& board, string &word)
    {
        if(idx == word.size()) return 1;
        if(x < 0 || x == board.size() || y < 0 || y == board[0].size()) return 0;
        if(word[idx] != board[x][y]) return 0;
        int ret = -1;
        board[x][y] = '1';
        for(int i = 0; i < 4; i++)
        {
            ret = max(ret, find(x + dx[i], y + dy[i], idx + 1, board, word));
        }
        board[x][y] = word[idx];
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                int check = find(i, j, 0, board, word);
                if(check == 1) return true;
            }
        }
        return false;
    }
};
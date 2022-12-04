#include <iostream>
#include<vector>
using namespace std;

int answer = 0, row, col;
int cache[1000][1000] = {0};

int find(int x, int y, vector<vector<int>> & board)
{
    if(x < 0 || x >= row || y < 0 || y >= col || !board[x][y]) return 0;
    int & ret = cache[x][y];
    if(ret) return ret;
    ret = 10000;
    ret = min(ret, find(x + 1, y, board));
    ret = min(ret, find(x, y + 1, board));
    ret = min(ret, find(x + 1, y + 1, board));
    ret++;
    answer = max(answer, ret);
    return ret;
}

int solution(vector<vector<int>> board)
{
    row = board.size();
    col = board[0].size();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] && !cache[i][j])
            {
                find(i, j, board);
            }
        }
    }

    return answer * answer;
}
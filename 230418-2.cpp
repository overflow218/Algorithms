#include <string>
#include <vector>
using namespace std;

int solution(vector<string> board) {
    int o = 0, x = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 'O') o++;
            if(board[i][j] == 'X') x++;
        }
    }
    if(o - x > 1 || o < x) return 0;
    
    int oFinish = 0, xFinish = 0;
    // -> 가로 같은거 있는지 체크
    for(int i = 0; i < 3; i++)
    {
        if(board[i] == "OOO") oFinish++;
        if(board[i] == "XXX") xFinish++;
    }
    // 세로 체크
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if(board[0][i] == 'O') oFinish++;
            if(board[0][i] == 'X') xFinish++;
        }
    }
    // 대각선 체크
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] == 'O') oFinish++;
        if(board[0][0] == 'X') xFinish++;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if(board[0][2] == 'O') oFinish++;
        if(board[0][2] == 'X') xFinish++;
    }
    
    if(oFinish > 0 && xFinish > 0) return 0;
    if(oFinish == 2) return (o == 5 && x == 4) ? 1 : 0;
    if(oFinish == 1) return o > x ? 1 : 0;
    if(xFinish == 1) return o == x ? 1 : 0;
    return 1;
}
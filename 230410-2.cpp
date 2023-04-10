#include <string>
#include <vector>

using namespace std;

int pSum[1001][1001] = {0};
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    for(int i = 0; i < skill.size(); i++)
    {
        int type = skill[i][0], r1 = skill[i][1], c1 = skill[i][2], r2 = skill[i][3], c2 = skill[i][4], degree = skill[i][5];
        int flag = type == 1 ? -degree : degree;
        pSum[r1][c1] += flag;
        pSum[r2 + 1][c1] -= flag;
        pSum[r1][c2 + 1] -= flag;
        pSum[r2 + 1][c2 + 1] += flag;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 && j > 0)
            {
                pSum[0][j] += pSum[0][j-1];
            }
            if(i > 0 && j == 0)
            {
                pSum[i][0] += pSum[i - 1][0];
            }
            if(i > 0 && j > 0)
            {
                pSum[i][j] += pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
            }
            if(pSum[i][j] + board[i][j] > 0) answer++;
        }
    }    
    return answer;
}
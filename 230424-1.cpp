#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 100;
    int row = beginning.size();
    int column = beginning[0].size();
    int limit = 1 << (20);
    for(int check = 0; check < limit; check++)
    {
        bool flipRow[10] = {false};
        bool flipCol[10] = {false};
        int cnt = 0;
        for(int i = 0; i < row; i++)
        {
            if(check & (1 << i)) flipRow[i] = true;
        }
        for(int i = row; i < row + column; i++)
        {
            if(check & (1 << i)) flipCol[i - row] = true;
        }
        
        for(int r = 0; r < row; r++)
        {
            if(flipRow[r])
            {
                cnt++;
                for(int j = 0; j < column; j++)
                {
                    beginning[r][j] = (beginning[r][j] + 1) % 2;
                }
            }
        }

        for(int c = 0; c < column; c++)
        {
            if(flipCol[c])
            {
                cnt++;
                for(int j = 0; j < row; j++)
                {
                    beginning[j][c] = (beginning[j][c] + 1) % 2;
                }
            }
        }
        
        bool isDone = true;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(beginning[i][j] != target[i][j])
                {
                    isDone = false;
                    break;
                }
            }
            if(!isDone) break;
        }
        
        if(isDone)
        {
            answer = min(answer, cnt);
        }

        for(int r = 0; r < row; r++)
        {
            if(flipRow[r])
            {
                for(int j = 0; j < column; j++)
                {
                    beginning[r][j] = (beginning[r][j] + 1) % 2;
                }
            }
        }

        for(int c = 0; c < column; c++)
        {
            if(flipCol[c])
            {
                for(int j = 0; j < row; j++)
                {
                    beginning[j][c] = (beginning[j][c] + 1) % 2;
                }
            }
        }
    }
    return answer == 100 ? -1 : answer;
}
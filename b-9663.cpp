#include <iostream>
using namespace std;

bool board[15][15] = {false};
bool isVisited[15] = {false};
int n;
int ans = 0;

void queen(int row)
{
    if(row == n) 
    {
        ans++;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!isVisited[i])
        {
            bool isPossible = true;
            // 대각선 왼쪽위 체크 
            int x = row, y = i;
            while(x >= 0 && y >= 0)
            {
                if(board[x][y])
                {
                    isPossible = false;
                    break;
                }
                x--;
                y--;
            }
            
            // 대각선 오른쪽 위 체크 
            x = row, y = i;
            while(isPossible && x >= 0 && y < n)
            {
                if(board[x][y])
                {
                    isPossible = false;
                    break;
                }
                x--;
                y++;
            }
            if(isPossible)
            {
                board[row][i] = true;
                isVisited[i] = true;
                queen(row + 1);
                board[row][i] = false;
                isVisited[i] = false;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    queen(0);
    printf("%d\n", ans);
    return 0;
}
#include<iostream>
#include <vector>
#include <deque>
using namespace std;

int ans = 0;
int n;

void print(vector<vector<int>> &board)
{
    printf("-----\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
void move(vector<vector<int>> &board, int type)
{
    // <- 왼쪽으로 밀기
    if(type == 0)
    {
        for(int r = 0; r < n; r++)
        {
            deque<int> tmp;
            for(int c = 0; c < n; c++)
            {
                if(board[r][c])
                {
                    tmp.push_back(board[r][c]);
                }
            }
            
            for(int i = 0; i < n; i++)
            {
                if(tmp.empty())
                {
                    board[r][i] = 0;
                } else 
                {
                    int a = tmp.front(), b = 0;
                    tmp.pop_front();
                    if(!tmp.empty() && tmp.front() == a)
                    {
                        b = tmp.front();
                        tmp.pop_front();
                    }
                    board[r][i] = a + b;
                }
            }
        }
    } 
    // -> 오른쪽으로 밀기
    else if(type == 1)
    {
        for(int r = 0; r < n; r++)
        {
            deque<int> tmp;
            for(int c = n - 1; c >= 0; c--)
            {
                if(board[r][c])
                {
                    tmp.push_back(board[r][c]);
                }
            }
            
            for(int i = 0; i < n; i++)
            {
                if(tmp.empty())
                {
                    board[r][n - 1 - i] = 0;
                } else 
                {
                    int a = tmp.front(), b = 0;
                    tmp.pop_front();
                    if(!tmp.empty() && tmp.front() == a)
                    {
                        b = tmp.front();
                        tmp.pop_front();
                    }
                    board[r][n - 1 - i] = a + b;
                }
            }
        }
    }
    // 위로 밀기
    else if(type == 2)
    {
        for(int c = 0; c < n; c++)
        {
            deque<int> tmp;
            for(int r = 0; r < n; r++)
            {
                if(board[r][c])
                {
                    tmp.push_back(board[r][c]);
                }
            }

            for(int i = 0; i < n; i++)
            {
                if(tmp.empty())
                {
                    board[i][c] = 0;
                } else 
                {
                    int a = tmp.front(), b = 0;
                    tmp.pop_front();
                    if(!tmp.empty() && tmp.front() == a)
                    {
                        b = tmp.front();
                        tmp.pop_front();
                    }
                    board[i][c] = a + b;
                }
            }
        }
    } 
    // 아래로 밀기
    else 
    {
        for(int c = 0; c < n; c++)
        {
            deque<int> tmp;
            for(int r = n - 1; r >= 0; r--)
            {
                if(board[r][c])
                {
                    tmp.push_back(board[r][c]);
                }
            }

            for(int i = 0; i < n; i++)
            {
                if(tmp.empty())
                {
                    board[n - 1 - i][c] = 0;
                } else 
                {
                    int a = tmp.front(), b = 0;
                    tmp.pop_front();
                    if(!tmp.empty() && tmp.front() == a)
                    {
                        b = tmp.front();
                        tmp.pop_front();
                    }
                    board[n - 1 - i][c] = a + b;
                }
            }
        }
    }
}

void find(vector<int> &chosen, vector<vector<int>> &board)
{
    if(chosen.size() == 5)
    {
        vector<vector<int>> copied (board.begin(), board.end());
        for(int i = 0; i < 5; i++)
        {
            move(copied, chosen[i]);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans = max(ans, copied[i][j]);
            }
        }
    } else 
    {
        for(int i = 0; i < 4; i++)
        {
            chosen.push_back(i);
            find(chosen, board);
            chosen.pop_back();
        }
    }
}
int main()
{
    scanf("%d", &n);
    vector<vector<int>> board(n, vector<int>(n));
    vector<int> chosen;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    find(chosen, board);
    printf("%d\n", ans);
    return 0;
}
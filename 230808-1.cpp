#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
bool isRowDone[9][10] = {false};
bool isColDone[9][10] = {false};
bool isBlockDone[9][10] = {false};
bool isDone = false;
vector<pair<int, int>> check;

int getBlockNumber(int x, int y)
{
    return 3 * (x / 3) + (y / 3);
}

bool isGood(int x, int y, int num)
{
    if(isRowDone[x][num]) return false;
    if(isColDone[y][num]) return false;
    if(isBlockDone[getBlockNumber(x, y)][num]) return false;
    return true; 
}

void sdoku(int idx)
{
    if(isDone) return;
    if(idx == check.size())
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        isDone = true;
        return;
    }

    int x = check[idx].first, y = check[idx].second;
    for(int i = 1; i <= 9; i++)
    {
        if(isGood(x, y, i))
        {
            int block = getBlockNumber(x, y);
            board[x][y] = i;
            isRowDone[x][i] = isColDone[y][i] = isBlockDone[block][i] = true;
            sdoku(idx + 1);
            board[x][y] = 0;
            isRowDone[x][i] = isColDone[y][i] = isBlockDone[block][i] = false;
        }
    }
}


int main()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 0)
            {
                check.push_back(make_pair(i, j));
            }
            if(board[i][j] != 0)
            {
                isRowDone[i][board[i][j]] = true;
                isColDone[j][board[i][j]] = true;
                isBlockDone[getBlockNumber(i,j)][board[i][j]] = true;
            }
        }
    }

    // printf("-------\n");
    sdoku(0);
    return 0;
}
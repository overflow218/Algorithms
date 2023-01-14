#include <iostream>
#include <vector>
#include <set>
using namespace std;

char board[1000][1001] = {0};
int group[1000][1000] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<int> connected = {0};
int n, m;

int find(int x, int y, int groupCounter)
{
    if(x < 0 || x == n || y < 0 || y == m || board[x][y] == '1' || group[x][y] != 0) return 0;
    group[x][y] = groupCounter;
    int ret = 1;
    for(int i = 0; i < 4; i++)
    {
        ret += find(x + dx[i], y + dy[i], groupCounter);
    }
    return ret;
}

int main()
{
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", board[i]);
    }
    int groupCounter = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == '0' && group[i][j] == 0)
            {
                connected.push_back(find(i, j, groupCounter++));
            }
        }
    }

    // printf("-------\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == '0')
            {
                printf("0");
            } else 
            {
                set<int> s;
                for(int k = 0; k < 4; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0 || x == n || y < 0 || y == m || board[x][y] == '1') continue;
                    s.insert(group[x][y]);
                }
                int cnt = 1;
                set<int>:: iterator it;
                for(it = s.begin(); it != s.end(); it++)
                {
                    cnt += connected[*it];
                }
                printf("%d", cnt % 10);
            }
        }
        printf("\n");
    }
    return 0;
}
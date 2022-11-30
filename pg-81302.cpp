#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool isSafe = true;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isVisited[5][5] = {false};
void dfs(int x, int y, int count, vector<string>& place)
{
    if(x < 0 || x >= 5 || y < 0 || y >= 5 || place[x][y] == 'X' || count > 2 || isVisited[x][y]) return;
    if(count > 0 && place[x][y] == 'P')
    {
        isSafe = false;
        return;
    }
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        dfs(x + dx[i], y + dy[i], count + 1, place);
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int stage = 0; stage < 5; stage++)
    {
        isSafe = true;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(places[stage][i][j] == 'P')
                {
                    isSafe = true;
                    memset(isVisited, 0, sizeof(isVisited));
                    dfs(i, j, 0, places[stage]);
                    if(!isSafe)
                    {
                        break;
                    }
                }
            }
            if(!isSafe)
            {
                break;
            }
        }
        answer.push_back(isSafe ? 1 : 0);
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool isVisited[100][100] = {false};

int n, m;
int visit(int x, int y, vector<string> &maps)
{
    // 범위 벗어나면 바로 종료
    if (x < 0 || x == m || y < 0 || y == n)
        return 0;
    // 이미 방문한 점이거나 바다면 종료
    if (isVisited[x][y] || maps[x][y] == 'X')
        return 0;
    isVisited[x][y] = true;
    int ret = maps[x][y] - '0';

    for (int i = 0; i < 4; i++)
    {
        ret += visit(x + dx[i], y + dy[i], maps);
    }
    return ret;
}

// m * n 배열이라고 하자
vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    m = maps.size();
    n = maps[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!isVisited[i][j] && maps[i][j] != 'X')
            {
                answer.push_back(visit(i, j, maps));
            }
        }
    }
    if (answer.empty())
        return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}
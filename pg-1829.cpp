#include <vector>
#include <cstring>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool isVisited[100][100] = {false};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int limitX, limitY;

int dfs(int x, int y, int color, vector<vector<int>> &picture)
{
    if(x < 0 || x >= limitX || y < 0 || y >= limitY || isVisited[x][y]) return 0;
    if(picture[x][y] != color) return 0;
    int tmp = 1;
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        tmp += dfs(x + dx[i], y + dy[i], color, picture);
    }
    return tmp;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);

    limitX = m;
    limitY = n;
    memset(isVisited, 0, sizeof(isVisited));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(picture[i][j] && !isVisited[i][j])
            {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, dfs(i, j, picture[i][j], picture));
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
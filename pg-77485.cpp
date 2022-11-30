#include <string>
#include <vector>

using namespace std;

int box[101][101] = {0};

void show(int rows, int columns)
{
    printf("----------------\n");
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            printf("%.2d ", box[i][j]);
        }
        printf("\n");
    }
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt = 1;
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            box[i][j] = cnt++;
        }
    }

    for(int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][0], y1 = queries[i][1], x2 = queries[i][2], y2 = queries[i][3];
        int leftTop = box[x1][y1], leftBottom = box[x2][y1], rightTop = box[x1][y2], rightBottom = box[x2][y2];
        int tmpMin = 10001;
        
        tmpMin = min(tmpMin, leftBottom);
        tmpMin = min(tmpMin, leftTop);
        tmpMin = min(tmpMin, rightBottom);
        tmpMin = min(tmpMin, rightTop);
        // -> 회전
        for(int y = y2 - 1; y > y1; y--)
        {
            tmpMin = min(tmpMin, box[x1][y]);
            box[x1][y + 1] = box[x1][y];
        }
        box[x1][y1 + 1] = leftTop;
        // | 아래로 내려가기
        for(int x = x2 - 1; x > x1; x--)
        {
            tmpMin = min(tmpMin, box[x][y2]);
            box[x + 1][y2] = box[x][y2];
        }
        box[x1 + 1][y2] = rightTop;
        // <- 회전
        for(int y = y1 + 1; y < y2; y++)
        {
            tmpMin = min(tmpMin, box[x2][y]);
            box[x2][y - 1] = box[x2][y];
        }
        box[x2][y2 - 1] = rightBottom;
        // | 위로 올라가기
        for(int x = x1 + 1; x < x2; x++)
        {
            tmpMin = min(tmpMin, box[x][y1]);
            box[x - 1][y1] = box[x][y1];
        }
        box[x2 - 1][y1] = leftBottom;
        answer.push_back(tmpMin);

    }

    return answer;
}
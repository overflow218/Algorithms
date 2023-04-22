#include <string>
#include <vector>

using namespace std;

bool isVisited[52][52] = {false};
int arr[52][52] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

/*
테두리 그릴수만 있으면 거리 구하는건 bfs로 바로 구해주면 됨. 
테두리의 원칙 인접한 4면중 1면은 빈공간, 3면은 직사각형의 공간 이면 되는게 기본인데
문제는 저 꺽이는 코너같은 곳에 있는 애들은 걔 자체는 위의 조건을 만족하지 않지만
*/
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(auto & rec:rectangle)
    {
        int lx = rec[0], ly = rec[1], rx = rec[2], ry = rec[3];
        for(int i = lx; i <= rx; i++)
        {
            for(int j = ly; j <= ry; j++)
            {
                arr[i][j] = 1;
            }
        }
    }
    
    for(int i = 1; i <= 50; i++)
    {
        // 왼쪽 테두리 찾기
        for(int j = 1; j <= 50; j++)
        {
            if(arr[i][j] > 0 && arr[i][j - 1] == 0)
            {
                arr[i][j] = 2;
            }
        }
        // 오른쪽 테두리 찾기
        for(int j = 50; j > 0; j--)
        {
            if(arr[i][j] > 0 && arr[i][j + 1] == 0)
            {
                arr[i][j] = 2;
            }
        }
    }
    
    for(int col = 1; col <= 50; col++)
    {
        // 위쪽 테두리 찾기
        for(int row = 1; row <= 50; row++)
        {
            if(arr[row][col] > 0 && arr[row - 1][col] == 0)
            {
                arr[row][col] = 2;
            }
        }
        // 아래쪽 테두리 찾기
        for(int row = 50; row > 0; row--)
        {
            if(arr[row][col] > 0 && arr[row + 1][col] == 0)
            {
                arr[row][col] = 2;
            }
        }
    }
    
    for(int i = 0; i <= 20; i++)
    {
        for(int j = 0; j <= 20; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return answer;
}
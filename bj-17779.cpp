#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[21][21];
int population[21][21];
bool isVisited[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int garymender[6] = {0};
int totalPopulation = 0;
int X, Y, D1, D2, n;
int ans = 987654321;

// 유효한 인풋인지 확인
bool isValidInput(vector<int>&chosen)
{
    int x = chosen[0];
    int y = chosen[1];
    int d1 = chosen[2];
    int d2 = chosen[3];
    if(x + d1 + d2 > n) return false;
    if(y - d1 < 1 || y + d2 > n) return false;
    return true;
}
// 각 구역별로 유효한 좌표인지 확인
bool isValid(int x, int y, int type)
{
    // 구역 관계없이 범위 벗어나면 실패
    if(x <= 0 || x > n || y <= 0 || y > n) return false;
    if(type == 1)
    {
        // 이 경우만 유효
        if((1 <= x && x < X + D1) && (1 <= y && y <= Y)) return true;
        return false;
    }
    if(type == 2)
    {
        // 이 경우만 유효
        if((1 <= x && x <= X + D2) && (Y < y && y <= n)) return true;
        return false;
    }
    if(type == 3)
    {
        // 이 경우만 유효
        if((X + D1 <= x && x <= n) && (1 <= y && y < Y - D1 + D2)) return true;
        return false;
    }
    if(type == 4)
    {
        // 이 경우만 유효
        if((X + D2 < x && x <= n) && (Y - D1 + D2 <= y && y <= n)) return true;
        return false;
    }
    // 여기 내려오면 에러임!
    throw(-1);
}

void visit(int x, int y, int type)
{
    // 유효하지 않은 범위거나 이미 방문한 경우 종료
    if(!isValid(x, y, type) || isVisited[x][y]) return;
    isVisited[x][y] = true;
    garymender[type] += population[x][y];

    for(int i = 0; i < 4; i++)
    {
        visit(x + dx[i], y + dy[i], type);
    }
}
void dis5()
{
    for(int i = 0; i <= D1; i++)
    {
        isVisited[X + i][Y - i] = true;
    }
    for(int i = 0; i <= D2; i++)
    {
        isVisited[X + i][Y + i] = true;
    }

    for(int i = 0; i <= D2; i++)
    {
        isVisited[X + D1 + i][Y - D1 + i] = true;
    }
    for(int i = 0; i <= D1; i++)
    {
        isVisited[X + D2 + i][Y + D2 - i] = true;
    }
}

void check(vector<int>&chosen)
{
    // x, y, d1, d2를 다 골랐음. 이제 하나씩 실행만 해보면 됨.
    if(chosen.size() == 4)
    {
        // 유효하지 않은 x, y, d1, d2면 바로 종료
        if(!isValidInput(chosen)) return;
        X = chosen[0];
        Y = chosen[1];
        D1 = chosen[2];
        D2 = chosen[3];

        // 실제로 구역 찾는 코드
        memset(isVisited, 0, sizeof(isVisited));
        memset(garymender, 0, sizeof(garymender));
        
        // 5를 먼저 칠해줘야 나머지애들이 안넘어옴
        dis5();
        visit(1, 1, 1);
        visit(1, n, 2);
        visit(n, 1, 3);
        visit(n, n, 4);

        // 만약에 하나라도 0이면 규칙에 어긋남!
        garymender[5] = totalPopulation - garymender[1] - garymender[2] - garymender[3] - garymender[4];
        int big = 0, small = 987654321;
        for(int i = 1; i <= 5; i++)
        {
            big = max(big, garymender[i]);
            small = min(small, garymender[i]);
        }
        // 0인 구간이 있으면 안됨. 
        if(small == 0) return;
        ans = min(ans, big - small);

        // printf("x: %d, y: %d, d1; %d, d2: %d -> %d가 답\n", X, Y, D1, D2, big -small);
        // printf("g1; %d, g2: %d, g3: %d, g4: %d, g5: %d\n\n", garymender[1], garymender[2], garymender[3], garymender[4], garymender[5]);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        chosen.push_back(i);
        check(chosen);
        chosen.pop_back();
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &population[i][j]);
            totalPopulation += population[i][j];
        }
    }
    vector<int> vec;
    check(vec);

    printf("%d\n", ans);
    return 0;
}
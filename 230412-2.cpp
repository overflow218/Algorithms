#include <string>
#include <vector>

using namespace std;

// 문제 기준에 맡게 (x, y)에 기둥 혹은 보가 설치되었다고 생각해야겠다. 
// 즉 (x,y) == 2이면 (x, y) (x, y + 1) 에 기둥이 있는거고
// (x, y) == 1이면 (x,y) (x + 1, y) 에 보가 있는거임
bool bo[102][102] = {false};
bool gidoong[102][102] = {false};

// (x, y) ~ (x, y + 1) 에 있는 기둥이 안전한지 체크 ㅋㅋ
bool isGidoongSafe(int x, int y)
{
    // 바닥인 경우
    if(y == 0) return true;
    // 받쳐주는 기둥이 있는 경우
    if(gidoong[x][y - 1]) return true;
    // 받쳐주는 기둥이 없을때 
    if(!gidoong[x][y - 1])
    {
        // 받쳐주는 보가 있으면 괜춘
        if(bo[x][y] || (x > 0 && bo[x - 1][y])) return true;
    }
    // 그게 아니라면 위험
    return false;
}

// (x, y) ~ (x + 1, y)에 있는 보임
bool isBosafe(int x, int y)
{
    // 밑에 받쳐주는 기둥이 있는 경우 안전쓰
    if(gidoong[x][y - 1] || gidoong[x + 1][y - 1]) return true;
    // 그게 아니라면 양옆에 보가 있어야함. 
    if(x > 0 && bo[x - 1][y] && bo[x + 1][y]) return true;
    // 그 외에는 위험
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(const auto & inst: build_frame)
    {
        int x = inst[0], y = inst[1], a = inst[2], b = inst[3];
        // 기둥의 경우 (x, y) ~ (x, y + 1)에 설치/삭제
        if(a == 0)
        {
            // 기둥 설치
            if(b == 1)
            {
                if(isGidoongSafe(x, y)) gidoong[x][y] = true;
            }
            // 기둥 삭제
            if(b == 0)
            {
                // 일단 없애고 영향받는 애들이 안전한지 체크
                gidoong[x][y] = false;
                bool isOkayToRemove = true;
                
                if(gidoong[x][y+1]) isOkayToRemove &= isGidoongSafe(x, y + 1);
                if(bo[x][y+1]) isOkayToRemove &= isBosafe(x, y + 1);
                if(x > 0 && bo[x-1][y + 1]) isOkayToRemove &= isBosafe(x - 1, y + 1);
                
                // 없애면 안되는 경우
                if(!isOkayToRemove) gidoong[x][y] = true;
            }
        }
        // 보의 경우 (x, y) ~ (x + 1 ,y) 에 설치/삭제
        if(a == 1)
        {
            // 보 설치
            if(b == 1)
            {
                if(isBosafe(x, y)) bo[x][y] = true;
            }
            // 보 제거
            if(b == 0)
            {
                // 일단 없애고 영향받는 애들이 안전한지 체크
                bo[x][y] = false;
                bool isOkayToRemove = true;
                
                if(gidoong[x][y]) isOkayToRemove &= isGidoongSafe(x, y);
                if(gidoong[x + 1][y]) isOkayToRemove &= isGidoongSafe(x + 1, y);
                if(bo[x + 1][y]) isOkayToRemove &= isBosafe(x + 1, y);
                if(x > 0 && bo[x-1][y]) isOkayToRemove &= isBosafe(x - 1, y);
                
                // 없애면 안되는 경우
                if(!isOkayToRemove) bo[x][y] = true;
            }
        }
    }
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(gidoong[i][j]) answer.push_back({i, j, 0});
            if(bo[i][j]) answer.push_back({i, j, 1});
        }
    }
    return answer;
}
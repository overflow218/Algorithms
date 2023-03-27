#include <string>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool isVisited[5][5] = {false};

// 2칸 거리안에 만나는 경우가 있으면 참. 아니면 거짓
bool check(int x, int y, int cnt, vector<string> &room)
{
    // 범위 벗어나거나 파티션이 있으면 바로 종료
    if(x < 0 || x == 5 || y < 0 || y == 5 || room[x][y] =='X' || isVisited[x][y]) return false;
    // 시작점 말고 찾았으면 방역 위반 사례
    if(cnt > 0 && room[x][y] == 'P') return true;
    // 이미 두칸왔는데 아직 못찾았으면 바로 종료
    if(cnt == 2) return false;
    isVisited[x][y] = true;
    
    bool ret = false;
    for(int i = 0; i < 4; i++)
    {
        ret |= check(x + dx[i], y + dy[i], cnt + 1, room);
    }
    return ret;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < 5; i++)
    {
        bool goodRoom = true;
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                if(places[i][j][k] == 'P')
                {
                    memset(isVisited, false, sizeof(isVisited));
                    bool tmp = check(j, k, 0, places[i]);
                    if(tmp) 
                    {
                        goodRoom = false;
                        break;
                    }
                }
            }
            if(!goodRoom) break;
        }
        int ans = goodRoom ? 1 : 0;
        answer.push_back(ans);
    }
    return answer;
}
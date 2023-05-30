#include <string>
#include <vector>
using namespace std;
/*
일단 전체 8 * 8 이니까 64개의 칸밖에 없음. 
각 시계를 돌리는 순서는 중요하지 않음. 몇번 누르느냐가 중요함. 
근데 4번이상 돌리는건 의미가 없음. 
그래서 0, 1, 2, 3 크게 4가지 선택지만 있음. 
위에꺼 12시 만들어놓았는데 아래꺼 만들다가 위에꺼가 다시 돌아갈수도 있음. 
이런 불상사를 막기위해서 순서를 제한하는게 필요할듯함. 
무조건 위에서 아래로, 왼쪽에서 오른쪽으로 진행하는 순서를 사용할거임. 
근데 이렇게 풀면 맨 윗줄을 눌러서 바꾸는게 최선인 경우를 해결 못한다는 한계가 있음.
그래서 일단 맨 윗줄을 4 ^ n 방법으로 자유롭게 누르고, 맨 윗줄이 정해지면
나머지는 알아서 정해지니까 필요한 만큼 누른다음에 전체가 0이 되는 경우의 
최솟값을 구해주면 될듯
4 ^ 8 = 2 ^ 16 이 되는 경우에 대하여 각각 탐색하고 들어간느거니까 
64 * 4 1억은 안넘을듯. 
*/

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const int INF = 987654321;

int find(vector<vector<int>> & clocks, int idx, int cnt)
{
    // 돌려서 확인하기
    int n = clocks.size();
    if(idx == n)
    {
        vector<vector<int>> tmpClock(clocks.begin(), clocks.end());
        int tmp = cnt;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(tmpClock[i - 1][j] == 0) continue;
                int needed = 4 - tmpClock[i - 1][j];
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 0 || nx == n || ny < 0 || ny == n) continue;
                    tmpClock[nx][ny] = (tmpClock[nx][ny] + needed) % 4;
                }
                tmpClock[i][j] = (tmpClock[i][j] + needed) % 4;
                tmp += needed;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(tmpClock[n - 1][i] != 0) return INF;
        }
        return tmp;
    }
    
    int ret = INF;
    for(int i = 1; i <= 4; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            int nx = dx[k], ny = idx + dy[k];
            if(nx < 0 || nx == n || ny < 0 || ny == n) continue;
            clocks[nx][ny] = (clocks[nx][ny] + 1) % 4;
        }
        clocks[0][idx] = (clocks[0][idx] + 1) % 4;
        ret = min(ret, find(clocks, idx + 1, cnt + (i % 4)));
    }
    return ret;
}

int solution(vector<vector<int>> clockHands) {
    return find(clockHands, 0, 0);
}
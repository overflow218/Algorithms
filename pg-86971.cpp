#include <string>
#include <vector>
using namespace std;
bool isConnected[101][101] = {false};
bool isVisited[101] = {false};
int cnt = 0;
int limit;

void dfs(int idx)
{
    if(idx > limit) return;
    if(isVisited[idx]) return;
    isVisited[idx] = true;
    cnt++;
    for(int next = 1; next <= limit; next++)
    {
        if(isConnected[idx][next]) dfs(next);
    }
    isVisited[idx] = false; 
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    limit = n;
    for(int i = 0; i < wires.size(); i++)
    {
        isConnected[wires[i][0]][wires[i][1]] = true;
        isConnected[wires[i][1]][wires[i][0]] = true;
    }

// 하나씩 연결끊고 경우의수 구하기
    for(int i = 0; i < wires.size(); i++)
    {
        cnt = 0;
        isConnected[wires[i][0]][wires[i][1]] = false;
        isConnected[wires[i][1]][wires[i][0]] = false;
        dfs(1);
        answer = min(abs(n - 2 * cnt), answer);
        isConnected[wires[i][0]][wires[i][1]] = true;
        isConnected[wires[i][1]][wires[i][0]] = true;
    }
    return answer;
}
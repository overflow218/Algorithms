#include <string>
#include <vector>
#include <queue>
using namespace std;

// 이게 각자 최선을 다하는거니까 현재 플레이어가 최선을 다해도 질수밖에없으면
// 이전 플레이어는 무조건 이기는거고 현재 플레이어가 이기는 경우도 있으면 
// 이전 플레이어는 지는 경우도 있는거네 

#define convert(x, y) x * 5 + y
int r, c;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct state{
    int stage;
    int isVisited;
    pair<int, int> a;
    pair<int, int> b;
};

// 각자가 최선을 다하는 상황임.
int check(state& current)
{
    int stage = current.stage, isVisited = current.isVisited;
    pair<int, int> a = current.a;
    pair<int, int> b = current.b;

    if(stage % 2 == 0)
    {
        // 현재 칸이 무너졌는지 체크
        int tmp = convert(a.first, a.second);
        if((isVisited & (1 << tmp)) == 0) return 0;
        int big = 0, small = 0;
        bool canWin = false;
        for(int i = 0; i < 4; i++)
        {
            int nx = a.first + dx[i], ny = a.second + dy[i];
            if(nx < 0 || nx == r || ny < 0 || ny == c) continue;
            // 가려는 칸이 안비어있는지도 체크해야함 
            int next = convert(nx, ny);
            //갈 수 있는 경우
            if(isVisited & (1 << next))
            {
                state newState = {stage + 1, isVisited ^ (1 << tmp), make_pair(nx, ny), b};
                int ho = check(newState) + 1;
                // 내가 지는 경우
                if(ho % 2 == 0)
                {
                    big = max(big, ho);
                } else 
                {
                    canWin = true;
                    small = small == 0 ? ho : min(small, ho);
                }
            }
        }
        return canWin ? small : big;
    } else 
    {
        // 현재 칸이 무너졌는지 체크
        int tmp = convert(b.first, b.second);
        if((isVisited & (1 << tmp)) == 0) return 0;
        int big = 0, small = 0;
        bool canWin = false;
        for(int i = 0; i < 4; i++)
        {
            int nx = b.first + dx[i], ny = b.second + dy[i];
            if(nx < 0 || nx == r || ny < 0 || ny == c) continue;
            // 가려는 칸이 안비어있는지도 체크해야함 
            int next = convert(nx, ny);
            //갈 수 있는 경우
            if(isVisited & (1 << next))
            {
                state newState = {stage + 1, isVisited ^ (1 << tmp), a, make_pair(nx, ny)};
                int ho = check(newState) + 1;
                
                // 내가 지는 경우
                if(ho % 2 == 0)
                {
                    big = max(big, ho);
                } else 
                {
                    canWin = true;
                    small = small == 0 ? ho : min(small, ho);
                }
            }
        }
        return canWin ? small : big;
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    r = board.size(); c = board[0].size();
    int flag = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == 1)
            {
                flag |= (1 << (convert(i, j)));
            }
        }
    }
    // 누가 이기든지 상관없이 그냥 최대한 오래하면 되는거네 
    state start = {0, flag, make_pair(aloc[0], aloc[1]), make_pair(bloc[0], bloc[1])};
    int answer = check(start);
    
    return answer;
}
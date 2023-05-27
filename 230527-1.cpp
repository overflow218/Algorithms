#include <string>
#include <vector>
using namespace std;
/*
일단 주어지는 보드판의 크기는 100 * 100 이네 
최대 26개의 블록을 터뜨리면 되는거니까 26번 순회를 하는데 
매 조각을 돈다고 하면 매 순회마다 26번이 돌고 
각 조각마다 터뜨릴수 있는지를 체크하는데 최대 500의 시간이 든다고 하면
26 * 26 * 500 대충 요정도 시간복잡도니까 충분히 시간안에 들어올 수 있음
*/
string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<vector<pair<int, int>>> blocks = vector<vector<pair<int, int>>>(26);
    // 안터진 블록은 참, 터진 블록은 거짓
    bool isAlive[26] = {false};
    int blockCount = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] != '.' && board[i][j] != '*')
            {
                int idx = board[i][j] - 'A';
                blocks[idx].push_back(make_pair(i, j));
                if(!isAlive[idx])
                {
                    isAlive[idx] = true;
                    blockCount++;
                }
            }
        }
    }
    
    while(answer.size() < blockCount)
    {
        // 이번턴에 터뜨릴게 있으면 참, 없으면 거짓
        // 거짓이면 바로 종료함. 불가능한 경우임
        bool isOkay = false;
        for(int i = 0; i < 26; i++)
        {
            if(!isAlive[i]) continue;
            // 두 블록의 x좌표가 같은 경우
            if(blocks[i][0].first == blocks[i][1].first)
            {
                int s = min(blocks[i][0].second, blocks[i][1].second);
                int e = max(blocks[i][0].second, blocks[i][1].second);
                int x = blocks[i][0].first;
                bool isPossible = true;
                for(int j = s + 1; j <= e - 1; j++)
                {
                    if(board[x][j] != '.')
                    {
                        isPossible = false;
                        break;
                    }
                }
                
                if(isPossible)
                {
                    answer += 'A' + i;
                    isAlive[i] = false;
                    board[x][s] = '.';
                    board[x][e] = '.';
                    isOkay = true;
                    break;
                }
            }
            // 두 블록의 y좌표가 같은 경우
            if(blocks[i][0].second == blocks[i][1].second)
            {
                int s = min(blocks[i][0].first, blocks[i][1].first);
                int e = max(blocks[i][0].first, blocks[i][1].first);
                int y = blocks[i][0].second;
                bool isPossible = true;
                for(int j = s + 1; j <= e - 1; j++)
                {
                    if(board[j][y] != '.')
                    {
                        isPossible = false;
                        break;
                    }
                }
                
                if(isPossible)
                {
                    answer += 'A' + i;
                    isAlive[i] = false;
                    board[s][y] = '.';
                    board[e][y] = '.';
                    isOkay = true;
                    break;
                }
            }

            // ㄱ, ㄴ 으로 가능한지 체크
            if(blocks[i][0].second < blocks[i][1].second)
            {
                int x1 = blocks[i][0].first, y1 = blocks[i][0].second, x2 = blocks[i][1].first, y2 = blocks[i][1].second;

                bool way1 = true;
                bool way2 = true;
                for(int j = x1 + 1; j <= x2; j++)
                {
                    if(board[j][y1] != '.') way1 = false;
                }
                for(int j = y1; j <= y2 - 1; j++)
                {
                    if(board[x2][j] != '.') way1 = false;
                }
                
                for(int j = y1 + 1; j <= y2; j++)
                {
                    if(board[x1][j] != '.') way2 = false;
                }
                for(int j = x1 + 1; j <= x2 - 1; j++)
                {
                    if(board[j][y2] != '.') way2 = false;
                }
                if(way1 || way2)
                {
                    answer += 'A' + i;
                    isAlive[i] = false;
                    board[x1][y1] = '.';
                    board[x2][y2] = '.';
                    isOkay = true;
                    break;
                }
            }
            // ㄱ, ㄴ 을 뒤집은 방식으로 가능한지 체크
            if(blocks[i][0].second > blocks[i][1].second)
            {
                int x1 = blocks[i][0].first, y1 = blocks[i][0].second, x2 = blocks[i][1].first, y2 = blocks[i][1].second;

                bool way1 = true;
                bool way2 = true;
                for(int j = x1 + 1; j <= x2; j++)
                {
                    if(board[j][y1] != '.') way1 = false;
                }
                for(int j = y2 + 1; j <= y1; j++)
                {
                    if(board[x2][j] != '.') way1 = false;
                }
                
                for(int j = y2; j <= y1 - 1; j++)
                {
                    if(board[x1][j] != '.') way2 = false;
                }
                for(int j = x1 + 1; j <= x2 - 1; j++)
                {
                    if(board[j][y2] != '.') way2 = false;
                }
                if(way1 || way2)
                {
                    answer += 'A' + i;
                    isAlive[i] = false;
                    board[x1][y1] = '.';
                    board[x2][y2] = '.';
                    isOkay = true;
                    break;
                }
            }
        }

        if(!isOkay) return "IMPOSSIBLE";
    }
    return answer;
}

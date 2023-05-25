#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;

/*
어차피 정확한 영역을 구하는것도 아니니까 좌표를 압축해서
1 ~ 5000까지의 수들로 바꿔주면 편할거 같음. 
그냥 고려하기엔 너무 답없음. 전에 포스터 문제 해결했떤 것처럼
부분합을 활용해서 특정 네모 영역에 있는 쐐기의 개수를 빠르게 구할 수 있도록 하는게 좋을 거같음
*/
map<int, int> convX;
map<int, int> convY;
set<int> setX;
set<int> setY;

// cache[i][j] = 0,0부터 (i, j)사이에 들어있는 쐐기의 개수
int cache[5005][5005];
int solution(int n, vector<vector<int>> data) {
    convX.clear();
    convY.clear();
    setX.clear();
    setY.clear();
    memset(cache, 0, sizeof(cache));
    for(int i = 0; i < n; i++)
    {
        setX.insert(data[i][0]);
        setY.insert(data[i][1]);
    }

    int cnt = 1;
    for(auto it = setX.begin(); it != setX.end(); it++)
    {
        convX[*it] = cnt++;
    }
    cnt = 1;
    for(auto it = setY.begin(); it != setY.end(); it++)
    {
        convY[*it] = cnt++;
    }
    
    for(int i = 0; i < n; i++)
    {
        int cx = convX[data[i][0]], cy = convY[data[i][1]];
        data[i][0] = cx; data[i][1] = cy;
        cache[cx][cy]++;
        cache[cx][n + 1]--;
        cache[n + 1][cy]--;
        cache[n + 1][n + 1]++;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cache[i][j] += cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1];
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n ; i++)
    {
        int x1 = data[i][0], y1 = data[i][1];
        for(int j = i + 1; j < n; j++)
        {
            int x2 = data[j][0], y2 = data[j][1];
            if(x1 == x2 || y1 == y2) continue;
            int minX = min(x1, x2), minY = min(y1, y2);
            int maxX = max(x1, x2), maxY = max(y1, y2);
            int tmp = cache[maxX - 1][maxY - 1] - cache[minX][maxY - 1] - cache[maxX - 1][minY] + cache[minX][minY];
            if(tmp == 0) answer++;
        }
    }
    return answer;
}
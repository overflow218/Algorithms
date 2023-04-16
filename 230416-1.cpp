#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요. -> ㅇㅋㅇㅋ
int cache[500][500][2];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int M, N;
const int MOD = 20170805;

int visit(int x, int y, int d, vector<vector<int>> &city_map)
{
    // 범위 벗어나는 경우 종료
    if(x < 0 || x == M || y < 0 || y == N) return 0;
    if(x == M - 1 && y == N - 1) return 1;
    if(city_map[x][y] == 1) return 0;
    
    int &ret = cache[x][y][d];
    if(ret != -1)
    {
        // 2방향 모두 가능한 경우
        if(city_map[x][y] == 0)
        {
            return (cache[x][y][0] + cache[x][y][1]) % MOD;
        }
        // 온방향 그대로 가야하는 경우
        return ret;
    }
    
    // 그대로 직진해야하는 경우
    if(city_map[x][y] == 2)
    {
        return ret = visit(x + dx[d], y + dy[d], d, city_map);
    }
    // 2가지 방향 모두 가능한 경우
    if(city_map[x][y] == 0)
    {
        cache[x][y][0] = visit(x + dx[0], y + dy[0], 0, city_map);
        cache[x][y][1] = visit(x + dx[1], y + dy[1], 1, city_map);
        return (cache[x][y][0] + cache[x][y][1]) % MOD;
    }
    return 0;
}
int solution(int m, int n, vector<vector<int>> city_map) {
    M = m; N = n;
    memset(cache, -1, sizeof(cache));
    return visit(0, 0, 0, city_map) % MOD;
}
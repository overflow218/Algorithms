#include <string>
#include <vector>

using namespace std;

unsigned int keySet[4][20] = {0};
unsigned int lockSet[20] = {0};

// 키의 (0, 0)좌표(좌측 상단)을 x, y옮기고 키의 종류가 key일때 자물쇠를 다 채울수 있으면
// true 반환, 아니면 false 반환
int n, m;
bool check(int x, int y, int key)
{
    const unsigned int check = (1 << n) - 1;
    for(int i = 0; i < n; i++)
    {
        int row = i + y;
        unsigned int tmp = 0u;
        // 유효한 범위일때만 키값으로 넣어줌
        if(0 <= row && row < m) tmp = keySet[key][row];
        if(x > 0) tmp = tmp << x;
        if(x < 0) tmp = tmp >> abs(x);
        
        unsigned int result = lockSet[i] ^ tmp;
        if((result & check) != check) return false;
    }
    // 여기까지 왔으면 성공
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size(); m = key.size();
    for(int i = 0; i < n; i++)
    {
        unsigned int tmp = 0;
        for(int j = 0; j < n; j++)
        {
            if(lock[i][j] == 1)
            {
                tmp += (1u << j);
            }
        }
        lockSet[i] = tmp;
    }
        
    for(int i = 0; i < m; i++)
    {
        unsigned int key1 = 0u, key2 = 0u, key3 = 0u, key4 = 0u;
        for(int j = 0; j < m; j++)
        {
            if(key[i][j] == 1)
            {
                key1 += (1 << j);
            }
            if(key[m - 1 - j][i] == 1)
            {
                key2 += (1 << j);
            }
            if(key[m - 1 - i][m - 1 - j] == 1)
            {
                key3 += (1 << j);
            }
            if(key[j][m - 1 - i] == 1)
            {
                key4 += (1 << j);
            }
        }
        keySet[0][i] = key1;
        keySet[1][i] = key2;
        keySet[2][i] = key3;
        keySet[3][i] = key4;
    }
        
    for(int x = -n; x <= n; x++)
    {
        for(int y = -n; y <= n; y++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(check(x, y, k)) return true;
            }
        }
    }
    
    return false;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
일단 주어진 그림을 살펴보면 세로 단조 폴리오미노가 되려면 같은 가로줄에 있는게 
붙어있어야 한다는 걸 확인할 수 있음. 
그럼 각 줄에 몇개의 블록을 놓을지를 정해주고 각 블록을 좌 우로 움직이면서 몇개의 경우의 수가
가능할지를 고려해주는 방향으로 진행해야함. 
*/

const int MOD = 10000000;
int cache[101][101];


// 맨 윗줄에 head개의 블록이 있고 남은 블록이 left개일때의 가능한 폴리오미노 수를 반환
int polyOmino(int head, int left)
{
    // 남은 블록 없는 경우
    if(left == 0) return 1;
    int &ret = cache[head][left];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; i <= left; i++)
    {
        ret = (ret + polyOmino(i, left - i) * (head + i - 1)) % MOD;
    }
    return ret;
}

int main()
{
    int c, n;
    scanf("%d", &c);
    memset(cache, -1, sizeof(cache));
    for(int t = 0; t < c; t++)
    {
        scanf("%d", &n);
        int ret = 0;
        for(int i = 1; i <= n; i++)
        {
            ret = (ret + polyOmino(i, n - i)) % MOD;
        }
        printf("%d\n", ret);
    }
    return 0;
}
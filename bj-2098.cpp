#include <iostream>
#include <cstring>
using namespace std;

int n;
int cost[16][16] = {0};

// 0번 마을에서 출발해서 0번 마을로 돌아온다고 가정!
// cache[i][state] = i번 마을에서 현 상태가 state일때 0번마을까지 돌아갈때의 최소값을 구함
int cache[16][66000] = {0};
int find(int idx, int state)
{
    // 다 순회한 경우
    if(state == ((1 << n) - 1))
    {
        // 근데 다시 못갈수도 있어서 체크해줘야함.
        return cost[idx][0] > 0 ? cost[idx][0] : 200000000;
    }
    
    int &ret = cache[idx][state];
    if(ret != -1) return ret;
    ret = 200000000;

    for(int next = 0; next < n; next++)
    {
        // 방문 안했으면서 길이 있을때만 방문
        if((~state & (1 << next)) && cost[idx][next] > 0)
        {
            ret = min(ret, cost[idx][next] + find(next, state + (1 << next)));
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));

    int ans = find(0, 1);
    printf("%d\n", ans);
    return 0;
}

/*
4
0 10 0 0 
0 0 9 0
0 0 0 12
8 0 0 0 
*/
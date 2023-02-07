#include <iostream>
#include <cstring>
using namespace std;

// cache[i][j] = i번 더해서 현재 합이 j일떄 앞으로 합 n을 만드는 방법의 수
int cache[201][201];
const int MOD = 1000000000;
int n, k;

int find(int cnt, int num)
{
    if(num == n) return 1;
    if(cnt == k || num > n) return 0;

    int &ret = cache[cnt][num];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i <= n; i++)
    {
        ret = (ret + find(cnt + 1, num + i)) % MOD;
    }
    return ret;
}

int main()
{
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    printf("%d\n", find(0, 0));
    return 0;
}
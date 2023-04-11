#include <string>
#include <vector>
#include <cassert>
using namespace std;

long long cache[5001] = {1};
const long long MOD = 1000000007;
int solution(int n) {
    if(n % 2 == 1) return 0;
    cache[2] = 3;
    cache[4] = 11;
    for(int i = 6; i <= n; i+= 2)
    {
        // 조심조심 뺴기와 모듈로를 같이할때는 나누는걸 더하고 빼줘야 음수가 안나옴...
        // 모듈로는 음수에 대해서 내 생각과 다르게 작동하는 경우가 많기떄문에 조심합시다!
        cache[i] = (4 * cache[i - 2] - cache[i - 4] + MOD) % MOD;
    }
    assert(cache[n] > 0);
    return cache[n];
}
#include <string>
#include <vector>

using namespace std;

long long MOD = 1000000007;
long long cache[5001] = {1, 0, 3, 0, 11};

/*
cache[0] = 1
cache[2] = 3
cache[4] = cache[2] * 3 + cache[0] * 2
cache[6] = cache[4] * 3 + cache[2] * 2 + cache[0] * 2
cache[8] = cache[6] * 3 + cache[4] * 2 + cache[2] * 2 + cache[0] * 2

*/

long long solution(int n) {
    if(n % 2) return 0;

    for(int i = 6; i <= n; i += 2)
    {
        cache[i] = (cache[i - 2] * 4ll) % MOD;
        cache[i] = (cache[i] + MOD - cache[i - 4]) % MOD;
    }
    return cache[n];
}
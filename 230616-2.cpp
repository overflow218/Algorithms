/*
일단 1개짜리로 
f(n) = f(n - 1) + f(n - 2) + 2 * (f(n -3) + f(n - 5) + f(n - 7) ...)
f(n - 2) = f(n - 3) + f(n - 4) + 2 * (f(n - 5) + f(n - 7) ...)

이거 조합하면 
f(n) = f(n - 1) + f(n - 2) + f(n - 2) + 2 * f(n - 3) - f(n - 3) - f(n - 4)
= f(n - 1) + 2 * f(n - 2) + f(n - 3) - f(n - 4)

*/

class Solution {
public:
    const int MOD = 1000000007;
    int cache[1001] = {0};

    int numTilings(int n) {
        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 5;
        cache[4] = 11;

        for(int i = 5; i <= n; i++)
        {
            cache[i] = (2 * cache[i - 2]) % MOD;
            cache[i] = (cache[i] + cache[i - 1]) % MOD;
            cache[i] = (cache[i] + cache[i - 3]) % MOD;
            cache[i] = (cache[i] + cache[i - 4]) % MOD;
        }
        return cache[n];
    }
};
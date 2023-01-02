#include <cmath>

class Solution {
public:
    bool isPrime(int x)
    {
        if(x == 2) return true;
        if(x == 1 or x % 2 == 0) return false;
        int limit = sqrt(x);
        for(int i = 3; i <= limit; i++)
        {
            if(x % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for(int i = left; i <= right; i++)
        {
            if(isPrime(i))
            {
                prime.push_back(i);
            }
        }
        if(prime.size() < 2) return {-1, -1};
        int gap = prime[1] - prime[0];
        vector<int> ans = {prime[0], prime[1]};
        for(int i = 1; i < prime.size() - 1; i ++)
        {
            if(prime[i + 1] - prime[i] < gap)
            {
                ans[0] = prime[i];
                ans[1] = prime[i + 1];
                gap = prime[i + 1] - prime[i];
            }
        }
        return ans;
    }
};
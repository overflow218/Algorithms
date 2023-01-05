#include <cstring>

class Solution {
public:
    vector<int> prime;
    void init(vector<bool> & isPrime){
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i < isPrime.size(); i++)
        {
            if(!isPrime[i]) continue;
            prime.push_back(i);
            for(int j = 2; j * i < isPrime.size(); j++)
            {
                isPrime[i * j] = false;
            }
        }
    }
    int smallestValue(int n) {
        vector<bool> isPrime(n + 1, true);
        init(isPrime);
        
        while(n > 1 && !isPrime[n])
        {
            int nextN = 0;
            int prev = n;
            for (int i = 0; i < prime.size(); i++)
            {
                if(n == 1) break;
                while(n % prime[i] == 0)
                {
                    nextN += prime[i];
                    n /= prime[i];
                }
            }
            if(prev != nextN)
            {
                n = nextN;
            } else 
            {
                return nextN;
            }
        }
        return n;
    }
};
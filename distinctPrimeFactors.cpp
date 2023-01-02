#include <cmath>
class Solution {
public:
    int isPrime(int x) {
        int limit = sqrt(x);
        for(int i = 3; i <= limit; i++)
        {
            if(x % i == 0) return false;
        }
        return true;
    }
    
    bool isDone(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]) return false;
        }
        return true;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> prime = {2, 3, 5, 7};
        for(int i = 9; i <= 1000; i = i + 2)
        {
            if(isPrime(i))
            {
                prime.push_back(i);
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < prime.size(); i++)
        {
            bool isGood = false;
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j] % prime[i] == 0)
                {
                    isGood = true;
                    while(nums[j] % prime[i] == 0)
                    {
                        nums[j] /= prime[i];
                    }
                }
            }
            cnt += isGood ? 1 : 0;
            if(isDone(nums)) break;
        }
        
        return cnt;
    }
};
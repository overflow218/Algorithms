/*
leetcode 2147번
*/

class Solution {
public:

    // 2 이상의 짝수
    bool isGood(int x)
    {
        return x > 0 && (x % 2 == 0);
    }
    
    int numberOfWays(string corridor) {
        const long long MOD = 1000000007;
        long long ans = 1;
        long long div = 0;
        int cnt = 0;
        
        for(int i = 0; i < corridor.size(); i++)
        {
            if(isGood(cnt)) div++;
            if(corridor[i] == 'S')
            {
                if(isGood(cnt))
                {
                    ans = (ans * div) % MOD;
                    div = 0;
                }
                cnt++;
            }
        }

        return isGood(cnt) ? ans : 0;
    }
};

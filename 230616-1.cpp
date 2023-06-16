class Solution {
public:
    const long long MOD = 1000000007;
    long long bino[1001][1001] = {0};
    bool initialized = false;

    void initialize()
    {
        bino[1][0] = bino[1][1] = 1;
        for(int i = 0; i <= 1000; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i) bino[i][j] = 1ll;
                else bino[i][j] = (bino[i - 1][j] + bino[i - 1][j - 1]) % MOD;
            }
            if(i == 0)
            {
                for(int j = 0; j <= 1000; j++)
                {
                    bino[0][j] = 1;
                }
            }
        }
    }

    long long check(vector<int>& nums) {
        if(!initialized)
        {
            initialize();
            initialized = true;
        } 
        if(nums.size() == 0) return 1;
        vector<int> left;
        vector<int> right;
        int root = nums[0];
        for(const int &num:nums)
        {
            if(num < root) left.push_back(num);
            if(num > root) right.push_back(num);
        }

        long long cnt1 = check(left);
        long long cnt2 = check(right);
        long long p = bino[nums.size() - 1][left.size()];
        return (((p * cnt1) % MOD) * cnt2) % MOD;
    }

    long long numOfWays(vector<int>& nums) {
        return check(nums) - 1;
    }
};
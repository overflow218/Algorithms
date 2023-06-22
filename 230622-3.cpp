class Solution {
public:
    int pSum[2000] = {0};
    int n;
    int cache[2000][2000] = {0};
    int find(int i, int k)
    {
        if(k - i < 4) return -1;
        int &ret = cache[i][k];
        if(ret != 0) return ret;
        int p1 = pSum[i - 1];
        int p4 = pSum[n - 1] - pSum[k];

        // j를 정해서 찾는다
        if(p1 == p4)
        {
            for(int j = i + 2; j <= k - 2; j++)
            {
                int p2 = pSum[j - 1] - pSum[i];
                int p3 = pSum[k - 1] - pSum[j];
                if(p2 == p3 && p1 == p2) return ret = 1;
            }
        }
        ret = max(find(i + 1, k), find(i, k - 1));
        return ret;
    }
    bool splitArray(vector<int>& nums) {
        n = nums.size();
        if(n < 7) return false;
        // n이 최대 7개는 되어야함. 안그러면 의미가 없음. 
        pSum[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            pSum[i] += pSum[i - 1] + nums[i];
        }

        return find(1, n - 2) == 1;
    }
};
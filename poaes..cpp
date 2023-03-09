#include <cmath>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pos[31] = {0};
        int neg[31] = {0};
        for(const int&num: nums)
        {
            if(num >= 0)
            {
                pos[num]++;
            } else
            {
                neg[abs(num)]++;
            }
        }
        if(pos[0] >= 2)
        {
            return vector<int>(nums.size(), 0);
        }

        vector<int> ans;
        for(const int&num: nums)
        {
            int tmp = 1;
            for(int i = 0; i <= 30; i++)
            {
                int cnt = pos[i];
                if(num == i) cnt--;
                if(cnt > 0)
                {
                    tmp = tmp * (int)pow(i, cnt);
                }
            }
            for(int i = 1; i <= 30; i++)
            {
                int cnt = neg[i];
                if(num == -i) cnt--;
                if(cnt > 0)
                {
                    tmp = tmp * (int)pow(i, cnt);
                }
                if(cnt % 2 == 1)
                {
                    tmp = -tmp;
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
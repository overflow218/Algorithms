#include <queue>
class Solution {
public:
    int convert[10] = {0, 1, 0, 0, 0, 0, 9, 0, 8, 6};
    int check[5] = {0, 1, 6, 8, 9};
    bool isValid(int n)
    {
        int tmp = n;
        int cnt = 0;
        while(tmp)
        {
            cnt = cnt * 10 + convert[tmp % 10];
            tmp /= 10;
        }
        return cnt != n;
    }
    int confusingNumberII(int n) {
        queue<int> q;
        int ans = 0;
        for(int i = 1; i < 5; i++)
        {
            q.push(check[i]);
        }

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            if(cur > n) break;
            if(isValid(cur)) ans++;
            if(cur <= 100000000)
            {
                for(int i = 0; i < 5; i++)
                {
                    q.push(cur * 10 + check[i]);
                }
            }
        }
        return ans;
    }
};
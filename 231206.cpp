class Solution {
public:
    int totalMoney(int n) {
        int ans = 1;
        int today = 2;
        int prevMonday = 1;
        for(int i = 2; i <= n; i++)
        {
            ans += today;
            if(i % 7 == 0)
            {
                prevMonday++;
                today = prevMonday;
            } else 
            {
                today++;
            }
        }
        return ans;
    }
};

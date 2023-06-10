class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int leftCount = index + 1;
        int rightCount = n - index - 1;
        int s = 1, e = maxSum;
        int ans = 0;
        while(s <= e)
        {
            int mid = (s + e) / 2;
            long long total = 0;

            if(leftCount >= mid)
            {
                total += (long long)mid * (mid + 1) / 2;
                total += leftCount - mid;
            } else 
            {
                total += (long long)(2 * mid - leftCount + 1) * leftCount / 2;
            }

            if(rightCount >= mid - 1)
            {
                total += (long long)mid * (mid - 1) / 2;
                total += rightCount - (mid - 1);
            } else 
            {
                total += (long long)(2 * mid - rightCount - 1) * rightCount / 2;
            }
            
            if(total<= (long long)maxSum)
            {
                ans = max(ans, mid);
                s = mid + 1;
            } else 
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};
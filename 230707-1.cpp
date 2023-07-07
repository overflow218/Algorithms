class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, right = 0, ans = 0, limit = 0;
        int n = answerKey.size();
        // check max continuous T
        while(right < n)
        {
            if(answerKey[right] == 'F')
            {
                limit++;
                while(limit > k)
                {
                    if(answerKey[left] == 'F') limit--;
                    left++;
                }
            }
            right++;
            ans = max(ans, right - left);
        }

        left = right = limit = 0;
        // check max continuous F
        while(right < n)
        {
            if(answerKey[right] == 'T')
            {
                limit++;
                while(limit > k)
                {
                    if(answerKey[left] == 'T') limit--;
                    left++;
                }
            }
            right++;
            ans = max(ans, right - left);
        }

        return ans;
        
    }
};
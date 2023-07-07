class Solution {
public:
/*
사실 알파벳 26개에 대해서 하나씩으로 바꾸는걸로 하면
n * 26번이니까 단순하게 슬라이딩 윈도우 26번 돌리면 답 구할 수 있을듯?
더 까리한 방법이 있을라나?
*/
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int j = 0; j < 26; j++)
        {
            char target = 'A' + j;
            int start = 0, e = 0, limit = 0;
            while(e < n)
            {
                if(s[e] != target) limit++;
                e++;
                while(limit > k)
                {
                    if(s[start] != target) limit--;
                    start++;
                }
                ans = max(ans, e - start);
            }
        }
        return ans;
    }
};
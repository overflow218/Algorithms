class Solution {
public:
// 문자가 알파벳만 있다는 제한조건이 없음. 걍 셋으로 풀어야겠네 ㄷㄷ..
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int alphabet[26] = {0};
        int start = 0, e = 0, cnt = 0, ans = 0, n = s.size();
        while(e < n)
        {
            alphabet[s[e] - 'a']++;
            if(alphabet[s[e] - 'a'] == 1) cnt++;
            while(cnt > k)
            {
                alphabet[s[start] - 'a']--;
                if(alphabet[s[start] - 'a'] == 0) cnt--;
                start++;
            }
            e++;
            ans = max(ans, e - start);
        }
        return ans;
    }
};
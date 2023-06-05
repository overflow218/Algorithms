class Solution {
public:

    bool isVowel(char x)
    {
        switch (x)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < k; i++)
        {
            if(isVowel(s[i])) cnt++;
        }
        ans = cnt;
        for(int i = k; i < s.size(); i++)
        {
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i - k])) cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
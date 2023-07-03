class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt = 0;
        if(s.size() != goal.size()) return false;
        int alpha1[26] = {0};
        int alpha2[26] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != goal[i]) cnt++;
            alpha1[s[i] - 'a']++;
            alpha2[goal[i] - 'a']++;
        }

        bool countSame = true;
        for(int i = 0; i < 26; i++)
        {
            if(alpha1[i] != alpha2[i]) countSame = false;
        }

        if(countSame && cnt == 2) return true;
        if(cnt == 0)
        {
            for(int i = 0; i < 26; i++)
            {
                if(alpha1[i] >= 2) return true;
            }
        }
        return false;
    }
};
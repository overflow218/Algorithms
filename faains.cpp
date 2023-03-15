class Solution {
public:
    int pCounter[26] = {0};
    int sCounter[26] = {0};
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        for(int i = 0; i < p.size(); i++)
        {
            pCounter[p[i] - 'a']++;
        }
        int pSize = p.size();
        for(int i = 0; i < pSize; i++)
        {
            sCounter[s[i] - 'a']++;
        }

        for(int i = pSize; i <= s.size(); i++)
        {
            
            bool isPossible = true;
            for(int j = 0; j < 26; j++)
            {
                if(sCounter[j] < pCounter[j])
                {
                    isPossible = false;
                    break;
                }
            }

            if(isPossible)
            {
                ans.push_back(i - pSize);
            }
            if(i == s.size()) break;

            sCounter[s[i - pSize] - 'a']--;
            sCounter[s[i] - 'a']++;
        }
        return ans;
    }
};
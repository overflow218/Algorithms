class Solution {
public:
    int p[26];
    int find(int a)
    {
        if(p[a] == a) return a;
        return p[a] = find(p[a]);
    }

    void make(int a, int b)
    {
        int pA = find(a), pB = find(b);
        if(pA < pB)
        {
            p[pB] = pA;
        } else 
        {
            p[pA] = pB;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 26; i++)
        {
            p[i] = i;
        }

        for(int i = 0; i < s1.size(); i++)
        {
            make(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";
        for(int i = 0; i < baseStr.size(); i++)
        {
            ans += 'a' + find(baseStr[i] - 'a');
        }

        return ans;
    }
};
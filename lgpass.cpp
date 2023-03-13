#include <cstring>

class Solution {
public:
    int big = 0, start, end;
    int cache[1000][1000];
    int find(int s, int e, string & str)
    {
        if(s > e) return 0;
        if(s == e)
        {
            if(big < 1)
            {
                big = 1;
                start = s; end = e;
            }
            return 1;
        }

        int &ret = cache[s][e];
        if(ret != -1) return ret;
        ret = 0;
        find(s + 1, e, str);
        find(s, e - 1, str);

        if(str[s] == str[e])
        {
            if(s + 1 == e)
            {
                ret = 2;
            } else 
            {
                int ho = find(s + 1, e - 1, str) + 2;
                if(ho == e - s + 1) ret = ho;
            }
        }

        if(ret > big)
        {
            big = ret;
            start = s, end = e;
        }
        return ret;
    }
    string longestPalindrome(string s) {
        memset(cache, -1, sizeof(cache));
        find(0, (int)s.size() - 1, s);
        string ans = string(s.begin() + start, s.begin() + end + 1);
        return ans;
    }
};
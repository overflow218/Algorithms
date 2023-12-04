// leetcode 2264번
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";

        for(int i = 0; i < num.size() - 2; i++)
        {
            string tmp = num.substr(i, 3);
            if(isValid(tmp)) ans = max(ans, tmp);
        }

        return ans;
    }

    bool isValid(string x)
    {
        return x[0] == x[1] && x[1] == x[2];
    }
};

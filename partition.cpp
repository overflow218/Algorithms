class Solution {
public:
    vector<vector<string>> ans;
    string check = "";
    bool isPalindrome(int s, int e)
    {
        int start = s, end = e;
        while(start <= end)
        {
            if(check[start] != check[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void divide(int block, vector<int> &chosen)
    {
        if(block == 0)
        {
            // 각 경우마다 palidrome 인지 체크. 맞으면 추가
            int cnt = 0;
            vector<string> tmp;
            for(const int& sub_cnt:chosen)
            {
                if(!isPalindrome(cnt, cnt + sub_cnt - 1)) return;
                tmp.push_back(check.substr(cnt, sub_cnt));
                cnt += sub_cnt;
            }
            ans.push_back(tmp);
            return;
        }

        for(int i = 1; i <= block; i++)
        {
            chosen.push_back(i);
            divide(block - i, chosen);
            chosen.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<int> vec;
        check = s;
        divide(check.size(), vec);
        return ans;
    }
};
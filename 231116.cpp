/*
leetcode 1980번
일단 n이 16개 밖에 안되네
그럼 최대 2 ^ 16 이 가능하다는거 아니여~
어차피 하나만 찾으면 되는거니까
일단 0000이 없으면 그냥 0000 이 정답임!
0000이 있는 경우... 
*/

#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:

    int n;

    string check(string x)
    {
        int needed = n - x.size();
        return string(needed, '0') + x;
    }
    int convert(string x)
    {
        int tmp = 0;
        for(int i = 0; i < x.size(); i++)
        {
            if(x[i] == '1')
            {
                tmp += (int)pow(2, x.size() - 1 - i);
            }
        }
        return tmp;
    }

    // x 는 1이상 자연수라고 가정.
    string convert(int x)
    {
        string tmp = "";
        while(x > 0)
        {
            tmp = (x % 2 == 0 ? "0" : "1") + tmp;
            x /= 2;
        }
        return tmp;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> vec;
        n = nums.size();
        for(auto it: nums)
        {
            vec.push_back(convert(it));
            printf("%d\n", convert(it));
        }
        sort(vec.begin(), vec.end());
        if(vec[0] > 0) return string (n, '0');
        for(int i = 0; i < n - 1; i++)
        {
            if(vec[i] + 1 < vec[i + 1]) return check(convert(vec[i] + 1));
        }
        return check(convert(vec.back() + 1));
    }
};

#include <algorithm>
#include <vector>
using namespace std;

// leetcode 2785번
// 걍 자음 냅두고 모음만 다 모은다음에 정렬해서 넣어주면 될듯? 
// 한방에 보는건 별로 생각이 안나네. 뭐 스택같은거 쓰면 한번 순회에도 될것같긴한뎅 ㅋㅋ..
class Solution {
public:
    vector<char> check;

    bool isVowel(char c)
    {
        switch(c)
        {
            case 'A':
            case 'a':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return true;
            default:
                return false;
        }
    }
    string sortVowels(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            if(isVowel(s[i])) check.push_back(s[i]);
        }
        sort(check.begin(), check.end());

        int idx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isVowel(s[i])) s[i] = check[idx++];
        }
        return s;
    }
};

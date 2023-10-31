// leetcode 2433번
// 이건 걍 xor 개념을 알고있냐고 물어보는듯
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(int i = pref.size() - 1; i > 0; i--)
        {
            pref[i] ^= pref[i - 1];
        }
        return pref;
    }
};

/*
leetcode 2434번
생각해보자. 2가지 동작이 가능한데
1. s의 맨앞에서 떼어서, t의 맨뒤에 붙인다. 
2. t의 맨뒤에서 하나 떼어내서 종이에 적는다. 

s에서 t로 넘어가는 순서는 항상 고정되어 있음. 
근데 이게 문자열상으로 가장 앞에 있어야 한다는 소리지?

지금 t 맨위에 있는게 d인데 새로운 글자가 x라고 해보자. 
그러면 d를 쓰는게 맞니 아니면 x를 쓰는게 맞니?
당근 d를 쓰는게 맞지!
왜냐면 d를 안쓰면 x가 d보다 앞서게 되는 상황이 발생함. 
이거 약간 그리디로 생각해도 되는거 아닌가유
-> 맞네 탐욕적 선택속성이 있는거로 파악됨. 
x < y 인데 x를 안적고 y를 적은 최적해가 있다고 했을때
x 적고 y적으면 더 앞선 문자열이 나옴. 즉 이게 최적임.

ㅋㅋ 이거 안되네 바로 예제 걸리는구만. 담에 다시 풀어보기!
*/

#include <stack>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        string ans ="";
        stack<char> t;
        int idx = 0;
        while(idx < s.size() || !t.empty())
        {
            if(idx == s.size())
            {
                ans += t.top();
                t.pop();
                continue;
            }
            if(t.empty() || t.top() >= s[idx])
            {
                t.push(s[idx++]);
                continue;
            }
            if(t.top() < s[idx])
            {
                ans += t.top();
                t.pop();
            }
        }
        return ans;
    }
};

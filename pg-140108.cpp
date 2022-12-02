#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int idx = 0, limit = s.size(), cnt1 = 0, cnt2 = 0;
    char start;
    while(idx < limit)
    {
        if(cnt1 == 0)
        {
            cnt1 = 1;
            start = s[idx++];
            continue;
        }
        if(cnt1 == cnt2)
        {
            answer++;
            cnt1 = cnt2 = 0;
            continue;
        }
        if(s[idx++] == start)
        {
            cnt1++;
        } else 
        {
            cnt2++;
        }
    }
    return cnt1 > 0 ? answer + 1 : answer;
}
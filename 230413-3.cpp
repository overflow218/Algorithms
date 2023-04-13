#include <string>
#include <vector>
#include <cmath>
using namespace std;

int check(int x)
{
    if(x == 1) return 0;
    int limit = sqrt(x);
    int candidate = 1;
    for(int i = 2; i <= limit; i++)
    {
        if(x % i == 0)
        {
            int tmp = max(i, x / i);
            if(tmp <= 10000000) return tmp;
            // 1천만 이상인 경우.. 
            if(min(i, x/i) <= 10000000) candidate = max(candidate, min(i, x/i));
        }
    }
    return candidate;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i = begin; i <= end; i++)
    {
        answer.push_back(check(i));
    }
    return answer;
}
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 이거 채점 코드가 이상해서 멈춰놓은 상태
int find(int x)
{
    if(x == 1) return 0;
    if(x % 2 == 0) return x / 2;
    int limit = (int)sqrt(x);
    int ret = 1;
    for(int i = 3; i <= limit; i++)
    {
        if(x % i == 0)
        {
            ret = max(ret, max(i, x / i));
        }
    }
    return ret;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i = begin; i <= end; i++)
    {
        answer.push_back(find(i));
    }
    return answer;
}
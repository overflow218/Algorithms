#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;
    long long x = 0;
    long long limit = (long long)d * (long long)d;
    while (limit - x * x >= 0)
    {
        long long y = limit - x * x;
        int div = sqrt(y);
        answer += (div / k) + 1;
        x += k;
    }
    return answer;
}
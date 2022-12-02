#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long idx = 0;
    while(idx <= (long long)d)
    {
        answer += (int(sqrt((long long)d * d - idx * idx)) / k) + 1;
        idx += (long long)k;
    }
    return answer;
}

#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long onAxis = r2 - r1 + 1;
    long long cnt = 0;
    
    long long b1 = (long long)r1 * r1;
    long long b2 = (long long)r2 * r2;
    
    for(int x = 1; x < r2; x++)
    {
        long long tmp = (long long) x * x;
        int p1 = sqrt(b1 - tmp);
        if(b1 - tmp != (long long)p1 * p1) p1++;
        int p2 = sqrt(b2 - tmp);
        cnt += p2 - max(p1, 1) + 1;
    }
    return answer = 4 * (onAxis + cnt);
}
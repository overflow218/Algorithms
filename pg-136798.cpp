#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 사실상 약수 개수 구하는게 핵심인 문제네.

int getDivisorCount(int n)
{
    int limit = (int) sqrt(n);
    int cnt = 0;
    for(int i = 1; i <= limit; i++)
    {
        if(n % i == 0)
        {
            cnt += n / i == i ? 1 : 2;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> arr;
    for(int i = 1; i <= number; i++)
    {
        int tmpPower = getDivisorCount(i);
        if(tmpPower > limit)
        {
            answer += power;
        } else 
        {
            answer += tmpPower;
        }
    }
    return answer;
}
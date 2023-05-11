#include <string>
#include <vector>
using namespace std;
long long count[1001] = {0};

long long solution(vector<int> weights) {
    long long answer = 0;
    for(const int& w: weights)
    {
        count[w]++;
    }
    for(int i = 100; i <= 1000; i++)
    {
        if(count[i] == 0) continue;
        answer += count[i] * (count[i] - 1) / 2ll;
        for(int j = i + 1; j <= 1000; j++)
        {
            if(count[j] == 0) continue;
            if(i * 3 == j * 2 || i * 4 == j * 2 || i * 4 == j * 3) answer += count[i] * count[j];
        }
    }
    return answer;
}
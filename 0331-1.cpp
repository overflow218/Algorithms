#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int topA[10001] = {0};
    int topB[10001] = {0};
    int cntA = 0, cntB = 0, answer = 0;
    for(const int& top: topping)
    {
        if(topB[top] == 0) cntB++;
        topB[top]++;
    }
    
    for(const int& top: topping)
    {
        if(topA[top] == 0) cntA++;
        topA[top]++;
        topB[top]--;
        if(topB[top] == 0) cntB--;
        if(cntA == cntB) answer++;
    }
    return answer;
}
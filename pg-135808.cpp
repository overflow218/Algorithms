#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater());
    int idx = score.size() / m;
    for(int i = 1; i <= idx; i++)
    {
        answer += m * score[i * m - 1];
    }
    return answer;
}
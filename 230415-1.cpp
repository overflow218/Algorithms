#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>&a, vector<int>&b)
{
    if(a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    if(targets.size() == 1) return 1;
    sort(targets.begin(), targets.end(), cmp);
    targets.push_back({200000000, 200000000});
    
    int limit = targets[0][1];
    for(int i = 1; i < targets.size(); i++)
    {
        int s = targets[i][0], e = targets[i][1];
        if(s < limit) continue;
        // 그게 아니라면 미사일 날려야함 ㅋㅋ
        answer++;
        limit = e;
    }
    return answer;
}
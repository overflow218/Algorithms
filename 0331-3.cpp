#include <string>
#include <vector>
#include <set>
using namespace std;

multiset<int> s;
int solution(vector<int> stones, int k) {
    int answer = 2000000010;
    for(int i = 0; i < stones.size(); i++)
    {
        s.insert(stones[i]);
        // 제거해야하는게 있으면 제거
        if(i >= k) s.erase(s.find(stones[i - k]));
        // 값을 갱신해주기
        if(i >= k - 1) answer = min(answer, *s.rbegin());
    }
    return answer;
}
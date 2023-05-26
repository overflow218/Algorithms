#include <string>
#include <vector>
using namespace std;

/*
일단 단순히 완전탐색을 하기에도 명확한 방법이 잘 안보임.
그렇다고 그리디로 해보자니 
1. 그리디가 먹히는다는 보장이 없음
2. 그리디가 맞다고 하더라도 금과 은의 보유량을 고려해야하기 때문에 쉽지 않음. 
그래서 어차피 결국에 구하고자 하는건 시간이니까 
시간 기준으로 이분탐색을 하면서 x초를 주면 금과 은을 다 옮길 수 있는지를 체크해보는거임
한번에 1밖에 못옮긴다면 최대 10^9번 옮겨야하는데 왕복하면 20억번임
근데 금, 은 2개니까 40억번 왔다갔다해야하고, 한번 가는데 시간이 최대 10 ^ 5 이니까
4 * 10 ^14을 리미트로 두고 계산해야함.
*/
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 400000000000000, start = 1, end = 400000000000000;
    int n = g.size();
    while(start <= end)
    {
        long long mid = (start + end) / 2ll;
        long long gold = 0;
        long long silver = 0;
        long long total = 0;
        for(int i = 0; i < n; i++)
        {
            long long cnt = ((mid / t[i]) + 1) / 2;
            gold += (long long) min((long long)cnt * w[i], (long long)g[i]);
            silver += (long long) min((long long)cnt * w[i], (long long)s[i]);
            total += (long long) min((long long)g[i] + s[i], (long long)cnt * w[i]);
        }
        if(gold >= (long long)a && silver >= (long long)b && total >= (long long)a + b)
        {
            answer = min(answer, mid);
            end = mid - 1;
        } else 
        {
            start = mid + 1;
        }
    }
    return answer;
}
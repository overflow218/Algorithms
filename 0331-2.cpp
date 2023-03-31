#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<long long> q1;
queue<long long> q2;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
        sum1 += (long long)queue1[i];
        q2.push(queue2[i]);
        sum2 += (long long)queue2[i];
    }
    if((sum1 + sum2) % 2 == 1) return -1;
    int cnt = 0;
    int limit = 4 * queue1.size();
    while(cnt < limit)
    {
        if(sum1 == sum2) return cnt;
        cnt++;
        if(sum1 > sum2)
        {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
            continue;
        }
        if(sum1 < sum2)
        {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
    }
    return -1;
}
// # def solution(queue1, queue2):
// #     sum1 = sum(queue1)
// #     sum2 = sum(queue2)
// #     if((sum1 + sum2) % 2 == 1): return -1
// #     limit = len(queue1) * 2
// #     cnt = 0
// #     while(cnt < limit):
// #         if(sum1 > sum2):
// #             sum1 -= queue1[0]
// #             sum2 += queue1[0]
// #             queue2.append(queue1.pop(0))
// #         elif(sum1 < sum2):
// #             sum1 += queue2[0]
// #             sum2 -= queue2[0]
// #             queue1.append(queue2.pop(0))
// #         else:
// #             break
// #         cnt += 1
// #     return cnt if cnt != limit else -1

#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> q1, q2;
int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0;
    long long sum2 = 0;
    for(int i = 0; i < queue1.size(); i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }

    // int limit = queue1.size() * 2;
    int limit = 987654321;
    int cnt = 0;
    while(cnt < limit)
    {
        if(sum1 > sum2)
        {
            int tmp = q1.front();
            sum1 -= tmp;
            sum2 += tmp;
            q2.push(tmp);
            q1.pop();
        } else if(sum1 < sum2)
        {
            int tmp = q2.front();
            sum2 -= tmp;
            sum1 += tmp;
            q1.push(tmp);
            q2.pop();
        } else 
        {
            break;
        }
        cnt++;
    }

    return cnt < limit ? cnt : -1;
}
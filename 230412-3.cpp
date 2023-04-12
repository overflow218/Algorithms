#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    for(const int & e: enemy)
    {
        // 이번 라운드 못깨는 경우
        if(n < e)
        {
            // 지금 나온게 제일 커서 걍 여기다가 쓰는게 이득인 경우
            if(k > 0 && (pq.empty() || pq.top() <= e))
            {
                k--;
                answer++;
                continue;
            }
            // 그게 아니라면 이전꺼에서 찾아서 쓰는게 이득임
            while(k > 0 && !pq.empty())
            {
                k--;
                n += pq.top();
                pq.pop();
                if(n >= e) break;
            }
            // 무적권썼는데도 답이 없는경우
            if(n < e) break;
        }
        if(n >= e)
        {
            n -= e;
            pq.push(e);
        }
        answer++;
    }
    return answer;
}
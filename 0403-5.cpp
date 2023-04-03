#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int storey) {
    int answer = 100000000;
    queue<pair<int, int>> q;
    q.push(make_pair(storey, 0));
    while(!q.empty())
    {
        int current = q.front().first, cost = q.front().second;
        q.pop();
        printf("cur: %d, cost: %d\n", current, cost);
        if(current < 0) continue;
        if(current == 0)
        {
            answer = min(answer, cost);
            continue;
        }
        if(current % 10 == 0)
        {
            q.push(make_pair(current / 10, cost));
            continue;
        }
        int left = current % 10;
        q.push(make_pair(current - left, cost + left));
        q.push(make_pair(current + 10 - left, cost + 10 - left));
    }

    return answer;
}

int main()
{
    solution(16);
}
#include <string>
#include <vector>
#include <queue>
using namespace std;

// (나오는 시간, 들어간 코어 번호)
priority_queue<pair<int, int>> pq;
queue<int> avail;
int solution(int n, vector<int> cores) {
    int answer = 0;
    if(n <= cores.size()) return n;
    int counter = cores.size(), currentTime = 0;
    for(int i = 0; i < cores.size(); i++)
    {
        pq.push(make_pair(-cores[i], -i));
    }
    
    while(counter < n)
    {
        if(avail.empty())
        {
            int t = -pq.top().first, idx = -pq.top().second;
            pq.pop();
            currentTime = t;
            avail.push(idx);
        }
        counter++;
        int idx = avail.front();
        avail.pop();
        if(counter == n) return idx + 1;
        pq.push(make_pair(-currentTime - cores[idx], -idx));
    }
    return answer;
}
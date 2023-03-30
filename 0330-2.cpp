#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    // last 마지막 커버 위치, idx 현재 살펴볼 station의 인덱스
    int answer = 0, last = 0, idx = 0;
    while(last < n)
    {
        if(idx < stations.size() && last + 1 >= stations[idx] - w)
        {
            last = max(last, stations[idx++] + w);
            continue;
        }
        answer++;
        last += 2 * w + 1;
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int start = 0, end = 0, sum = 0, idx = 0;
    // {시작점, 개수}
    vector<pair<int, int>> candidate;
    while(idx < sequence.size())
    {
        while(sum > k)
        {
            sum -= sequence[start++];
        }
        if(sum < k)
        {
            sum += sequence[idx];
            end = idx++;
        } 
        if(sum == k)
        {
            candidate.push_back(make_pair(end - start, start));
            sum -= sequence[start++];
        }
    }
    
    while(sum > k)
    {
        sum -= sequence[start++];
    }
    if(sum == k)
    {
        candidate.push_back(make_pair(end - start, start));
        sum -= sequence[start++];
    }
    sort(candidate.begin(), candidate.end());
    int s = candidate.front().second, cnt = candidate.front().first;
    return {s, s + cnt};
}
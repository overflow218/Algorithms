#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> pSum;
    
    while(k != 1)
    {
        int next = k % 2 == 0 ? k / 2 : k * 3 + 1;
        double tmp = (next + k) / 2.0;
        if(!pSum.empty()) pSum.push_back(pSum.back() + tmp);
        if(pSum.empty()) pSum.push_back(tmp);
        k = next;
    }
    
    int limit = pSum.size();
    for(auto & range: ranges)
    {
        int start = range[0], b = range[1];
        int end = limit + b;
        if(start > end) answer.push_back(-1);
        if(start == end) answer.push_back(0);
        if(start < end)
        {
            if(start != 0) answer.push_back(pSum[end - 1] - pSum[start - 1]);
            if(start == 0) answer.push_back(pSum[end - 1]);
        }
    }
    return answer;
}
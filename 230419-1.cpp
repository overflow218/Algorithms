#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<pair<int, int>> startTime;
set<int> check;
void convert(string x)
{
    int h = (x[11] - '0') * 10 + (x[12] - '0');
    int m = (x[14] - '0') * 10 + (x[15] - '0');
    int s = (x[17] - '0') * 10 + (x[18] - '0');
    int ss = (x[20] - '0') * 100 + (x[21] - '0') * 10 + (x[22] - '0');
    int d[4] = {0};
    int idx = 0;
    for(int i = 24; i < x.size() - 1; i++)
    {
        if(x[i] != '.')
        {
            d[idx++] = x[i] - '0';
        }
    }
    int duration = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
    int time = h * 3600 + m * 60 + s;
    int total = time * 1000 + ss;
    startTime.push_back(make_pair(total - duration + 1, total));
}
int solution(vector<string> lines) {
    int answer = 0;
    for(int i = 0; i < lines.size(); i++)
    {
        convert(lines[i]);
    }
    sort(startTime.begin(), startTime.end());
    for(int i = 0; i < startTime.size(); i++)
    {
        int s = startTime[i].first, e = startTime[i].second;
        while(!check.empty())
        {
            int tmp = *check.begin();
            if(tmp > s - 1000) break;
            check.erase(check.begin());
        }
        check.insert(e);
        answer = max(answer, (int)check.size());
        // printf("s: %d, e: %d\n", s, e);
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> startTime;
vector<int> endTime;
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
    int e = time * 1000 + ss;
    int start = e - duration + 1 - 999;
    startTime.push_back(start);
    endTime.push_back(e);
}
int solution(vector<string> lines) {
    int answer = 0;
    for(int i = 0; i < lines.size(); i++)
    {
        convert(lines[i]);
    }
    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());
    int sIdx = 0, eIdx = 0, limit = lines.size(), cnt = 0;
    const int INF = 987654321;
    while(sIdx < limit || eIdx < limit)
    {
        int s = sIdx < limit ? startTime[sIdx] : INF;
        int e = eIdx < limit ? endTime[eIdx] : INF;

        if(s <= e && s != INF)
        {
            cnt++;
            sIdx++;
        }
        answer = max(cnt, answer);
        if(e <= s && e != INF)
        {
            cnt--;
            eIdx++;
        }
    }
    return answer;
}
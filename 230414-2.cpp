#include <string>
#include <vector>
#include <cstring>
using namespace std;

// 주어진 문자열을 초로 변환
int sToI(string log)
{
    int h = ((log[0] - '0') * 10 + log[1] - '0') * 3600;
    int m = ((log[3] - '0') * 10 + log[4] - '0') * 60;
    int s = (log[6] - '0') * 10 + log[7] - '0';
    return h + m + s;
}

// 초를 문자열로 변환
string iToS(int log)
{
    int s = log % 60;
    log /= 60;
    int m = log % 60;
    log /= 60;
    int h = log;
    string ret = to_string(h / 10) + to_string(h % 10) +":" + to_string(m / 10) + to_string(m % 10) +":" + to_string(s / 10) + to_string(s % 10);
    return ret;
}

long long pSum[3700000] = {0};
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int advLen = sToI(adv_time);
    int videoLen = sToI(play_time);
    for(int i = 0; i < logs.size(); i++)
    {
        int s = sToI(logs[i].substr(0, 8));
        int e = sToI(logs[i].substr(9));
        pSum[s + 1]++;
        pSum[e + 1]--;
    }

    for(int i = 1; i <= videoLen; i++)
    {
        pSum[i] += pSum[i - 1];
    }
    for(int i = 1; i <= videoLen; i++)
    {
        pSum[i] += pSum[i - 1];
    }
    
    int start = 0; 
    long long ans = 0;
    for(int s = 0; s < videoLen; s++)
    {
        int e = s + advLen;
        if(e > videoLen) break;
        
        long long tmp = pSum[e] - pSum[s];
        if(tmp > ans)
        {
            ans = tmp;
            start = s;
        }
    }
    return iToS(start);
}
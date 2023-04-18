#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

bool cmp(vector<string> &s1, vector<string> &s2)
{
    return s1[1] < s2[1];
}

int convert(string t)
{
    int h = (t[0] - '0') * 10 + t[1] - '0';
    int m = (t[3] - '0') * 10 + t[4] - '0';
    return h * 60 + m;
}

// (남은 시간, 과제이름)
deque<pair<int, string>> q;
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    int lastTime = convert(plans[0][1]);
    q.push_back(make_pair(stoi(plans[0][2]), plans[0][0]));
    for(int i = 1; i < plans.size(); i++)
    {
        int currentTime = convert(plans[i][1]);
        while(!q.empty())
        {
            int diff = currentTime - lastTime;
            if(diff < q.back().first)
            {
                q.back().first = q.back().first - diff;
                break;
            }
            if(diff >= q.back().first)
            {
                answer.push_back(q.back().second);
                lastTime += q.back().first;
                q.pop_back();
            }
        }
        lastTime = currentTime;
        q.push_back(make_pair(stoi(plans[i][2]), plans[i][0]));
    }
     while(!q.empty())
    {
         answer.push_back(q.back().second);
         q.pop_back();
    }
    return answer;
}
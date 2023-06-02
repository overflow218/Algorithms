#include "bridge.h"
using namespace std;

void find_bridges(int N)
{
    vector<int> countL(N + 1, 0);
    vector<int> countR(N + 1, 0);
    vector<int> left;
    vector<int> right;
    int prevCount = 0;
    for(int i = 1; i <= N; i++)
    {
        int cnt = count_crosses(1, i);
        
        if(cnt == -1)
        {
            countL[1]++;
            countR[i]++;
            prevCount = 0;
            continue;
        }
        countR[i - 1] += cnt - prevCount;
        prevCount = cnt;
    }
    prevCount = 0;
    for(int i = N; i > 0; i--)
    {
        int cnt = count_crosses(i, N);
        if(cnt == -1)
        {
            if(i == 1) continue;
            countL[i]++;
            countR[N]++;
            prevCount = 0;
            continue;
        }
        countL[i + 1] += cnt - prevCount;
        prevCount = cnt;
    }

    for(int i = 1; i <= N; i++)
    {
        if(countL[i] > 0)
        {
            for(int j = 0; j < countL[i]; j++)
            {
                left.push_back(i);
            }
        }
        if(countR[i] > 0)
        {
            for(int j = 0; j < countR[i]; j++)
            {
                right.push_back(i);
            }
        }
    }

    for(int i = 0; i < left.size(); i++)
    {
        report_bridge(left[i], right[i]);
    }
}
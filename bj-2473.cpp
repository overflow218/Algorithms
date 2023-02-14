#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, tmp;
    vector<long long> pos, neg;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp > 0)
        {
            pos.push_back(tmp);
        } else 
        {
            neg.push_back(tmp);
        }
    }

    long long ans = 3000000000;
    int a, b, c;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    if(pos.size() >= 3)
    {
        ans = pos[0] + pos[1] + pos[2];
        a = pos[0]; b = pos[1]; c = pos[2];
    }
    if(neg.size() >= 3)
    {
        if(ans > abs(neg[neg.size() - 3] + neg[neg.size() - 2] + neg[neg.size() - 1]))
        {
            ans = abs(neg[neg.size() - 3] + neg[neg.size() - 2] + neg[neg.size() - 1]);
            a = neg[neg.size() - 3]; b = neg[neg.size() - 2]; c = neg[neg.size() - 1];
        }
    }

    // 양수 2개, 음수 1개
    for(int i = 0; i < pos.size(); i++)
    {
        for(int j = i + 1; j < pos.size(); j++)
        {
            long long tmp = pos[i] + pos[j];
            int idx = lower_bound(neg.begin(), neg.end(), -tmp) - neg.begin();

            if(idx < neg.size())
            {
                long long check = abs(tmp + neg[idx]);
                if(check < ans)
                {
                    ans = check;
                    a = neg[idx]; b = pos[i]; c = pos[j];
                }
            }
            if(idx > 0)
            {
                long long check = abs(tmp + neg[idx - 1]);
                if(check < ans)
                {
                    ans = check;
                    a = neg[idx - 1]; b = pos[i]; c = pos[j];
                }
            }

        }
    }

    // 양수1개 음수 2개의 케이스
    for(int i = 0; i < neg.size(); i++)
    {
        for(int j = i + 1; j < neg.size(); j++)
        {
            long long tmp = neg[i] + neg[j];
            int idx = lower_bound(pos.begin(), pos.end(), -tmp) - pos.begin();

            if(idx < pos.size())
            {
                long long check = abs(tmp + pos[idx]);
                if(check < ans)
                {
                    ans = check;
                    a = neg[i]; b = neg[j]; c = pos[idx]; 
                }
            }
            if(idx > 0)
            {
                long long check = abs(tmp + pos[idx - 1]);
                if(check < ans)
                {
                    ans = check;
                    a = neg[i]; b = neg[j]; c = pos[idx - 1]; 
                }
            }
        }
    }

    printf("%d %d %d\n", a, b, c);
    return 0;
}
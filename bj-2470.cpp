#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pos, neg;
int main()
{
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp >= 0)
        {
            pos.push_back(tmp);
        } else 
        {
            neg.push_back(tmp);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int a, b, ans = 2000000000;
    if(pos.size() >= 2)
    {
        tmp = pos[0] + pos[1];
        if(tmp < ans)
        {
            ans = tmp;
            a = pos[0]; b = pos[1];
        }
    }
    if(neg.size() >= 2)
    {
        tmp = abs(neg[neg.size() - 2] + neg[neg.size() - 1]);
        if(tmp < ans)
        {
            ans = tmp;
            a = neg[neg.size() - 2]; b = neg[neg.size() - 1];
        }
    }
    for(int i = 0; i < pos.size(); i++)
    {
        int idx = lower_bound(neg.begin(), neg.end(), -pos[i]) - neg.begin();
        if(idx < neg.size())
        {
            tmp = abs(pos[i] + neg[idx]);
            if(ans > tmp)
            {
                ans = tmp;
                a = neg[idx]; b = pos[i];
            }
        }
        if(idx > 0)
        {
            tmp = abs(pos[i] + neg[idx - 1]);
            if(ans > tmp)
            {
                ans = tmp;
                a = neg[idx - 1]; b = pos[i];
            }
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> liquid;
int main()
{
    int n;
    long long tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        liquid.push_back(tmp);
    }
    sort(liquid.begin(), liquid.end());

    vector<long long> :: iterator it = lower_bound(liquid.begin(), liquid.end(), 0);
    // 0이상의 수들만 있는 경우
    if(it == liquid.begin())
    {
        printf("%lld %lld %lld\n", liquid[0], liquid[1], liquid[2]);
    } else if(it == liquid.end()) // 음수만 있는 경우
    {
        printf("%lld %lld %lld\n", liquid[n - 3], liquid[n - 2], liquid[n - 1]);
    }
    // 적어도 한개이상의 음수와 적어도 한개 이상의 0이상의 수가 있음.
    vector<vector<long long>> candidate;
    vector<long long> candiSum;

    int posIdx = it - liquid.begin();
    if(posIdx >= 3)
    {
        candidate.push_back({liquid[posIdx - 3], liquid[posIdx - 2], liquid[posIdx - 1]});
        candiSum.push_back(abs(liquid[posIdx - 3] + liquid[posIdx - 2] + liquid[posIdx - 1]));
    }
    if(posIdx >= 2)
    {
        candidate.push_back({liquid[posIdx - 2], liquid[posIdx - 1], liquid[posIdx]});
        candiSum.push_back(abs(liquid[posIdx - 2] + liquid[posIdx - 1] + liquid[posIdx]));
    }
    if(posIdx + 1 < n)
    {
        candidate.push_back({liquid[posIdx - 1], liquid[posIdx], liquid[posIdx + 1]});
        candiSum.push_back(abs(liquid[posIdx - 1] + liquid[posIdx] + liquid[posIdx + 1]));
    }
    if(posIdx + 2 < n)
    {
        candidate.push_back({liquid[posIdx], liquid[posIdx + 1], liquid[posIdx + 2]});
        candiSum.push_back(abs(liquid[posIdx + 2] + liquid[posIdx] + liquid[posIdx + 1]));
    }
    
    long long ans = 4000000000;
    int idx = -1;
    for(int i = 0; i < candidate.size(); i++)
    {
        if(candiSum[i] < ans)
        {
            ans = candiSum[i];
            idx = i;
        }
    }
    printf("%lld %lld %lld", candidate[idx][0], candidate[idx][1], candidate[idx][2]);
    return 0;
}
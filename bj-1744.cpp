#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


/*
양수, 음수 나눠서 생각해야하네 
양수정렬이랑 음수 정렬이랑 달라서 ㅠㅠ
*/
int main()
{
    int n, tmp;
    scanf("%d", &n);

    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if(tmp > 0)
        {
            pos.push_back(tmp);
        } else 
        {
            neg.push_back(tmp);
        }
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    int ans = 0;
    int idx = 0;
    while(idx < pos.size())
    {
        int a = pos[idx];
        if(idx + 1 < pos.size())
        {
            int b = pos[idx + 1];
            if(a * b > a + b)
            {
                ans += a * b;
                idx += 2;
                continue;
            }
        }
        ans += a;
        idx++;
    }
    idx = 0;
    while(idx < neg.size())
    {
        int a = neg[idx];
        if(idx + 1 < neg.size())
        {
            int b = neg[idx + 1];
            if(a * b > a + b)
            {
                ans += a * b;
                idx += 2;
                continue;
            }
        }
        ans += a;
        idx++;
    }
    printf("%d\n", ans);
    return 0;
}
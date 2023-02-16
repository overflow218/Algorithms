#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, ans = 2000000000;
    cin >> n >> m;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++)
    {
        if(m == 0)
        {
            if(i + 1 < n && nums[i] == nums[i + 1])
            {
                ans = 0;
                break;
            }
        } else 
        {
            int idx = lower_bound(nums.begin(), nums.end(), nums[i] + m) - nums.begin();
            if(idx < n)
            {
                ans = min(ans, nums[idx] - nums[i]);
            }
            if(ans == m) break;
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
3 0 
1 1 2 이런거 조심해야함 ㅋㅋ...
*/
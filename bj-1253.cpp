#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    map<int, int> counter;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
        counter[nums[i]]++;
    }

    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int check = nums[i] + nums[j];
            int idx = lower_bound(nums.begin(), nums.end(), check) - nums.begin();
            if(idx < n && nums[idx] == check)
            {
                if(nums[i] == 0 && nums[j] == 0 && counter[0] < 3) continue;
                if(nums[i] == check && counter[nums[i]] < 2 || nums[j] == check && counter[nums[j]] < 2) continue;
                s.insert(check);
            }
        }
    }

    int ans = 0;
    for(const int &good:s)
    {
        ans += counter[good];
    }
    cout << ans << '\n';
    return 0;
}
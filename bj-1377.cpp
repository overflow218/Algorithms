#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, tmp;
    cin >> n;
    vector<int> vec(n);
    vector<int> sortedVec(n);

    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sortedVec[i] = vec[i];
    }
    sort(sortedVec.begin(), sortedVec.end());
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int idx = lower_bound(sortedVec.begin(), sortedVec.end(), vec[i]) - sortedVec.begin();
        // 중복되는 수의 경우 제일 뒤의 인덱스로 생각해야함. 
        if(idx + 1 < n && sortedVec[idx + 1] == sortedVec[idx])
        {
            idx = upper_bound(sortedVec.begin(), sortedVec.end(), vec[i]) - sortedVec.begin();
            idx--;
        }
        ans = max(ans, i - idx);
    }

    cout << ans + 1 << '\n';
    return 0;
}
#include <algorithm>
using namespace std;

int ho;
bool cmp(int a, int b)
{
    int d1 = abs(a - ho);
    int d2 = abs(b - ho);
    if(d1 < d2 || (d1 == d2 && a < b)) return true;
    return false;
}
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        ho = x;
        sort(arr.begin(), arr.end(), cmp);
        vector<int> ans(arr.begin(), arr.begin() + k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
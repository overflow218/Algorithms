#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> sensor(n);
    vector<int> diff(n - 1);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &sensor[i]);
    }
    sort(sensor.begin(), sensor.end());
    for(int i = 0; i < n - 1; i++)
    {
        diff[i] = sensor[i + 1] - sensor[i];
    }
    sort(diff.begin(), diff.end());

    for(int i = 0; i < k - 1; i++)
    {
        if(diff.empty()) break;
        diff.pop_back();
    }
    int ans = 0;
    for(int i = 0; i < diff.size(); i++)
    {
        ans += diff[i];
    }
    printf("%d\n", ans);
    return 0;
}

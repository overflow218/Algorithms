#include <iostream>
using namespace std;

int arr[100010];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = arr[0];
    for(int i = 1; i < n; i++)
    {
        arr[i] = max(arr[i] + arr[i - 1], arr[i]);
        ans = max(arr[i], ans);
    }

    cout << ans << '\n';
    return 0;
}
#include <iostream>
using namespace std;

int arr[100] = {0};
long long cache[100][21] = {0};
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cache[0][arr[0]] = 1;

    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = 0; j <= 20; j++)
        {
            if(cache[i - 1][j] > 0)
            {
                if(j + arr[i] <= 20)
                {
                    cache[i][j + arr[i]] += cache[i - 1][j];
                }
                if(j - arr[i] >= 0)
                {
                    cache[i][j - arr[i]] += cache[i - 1][j];
                }
            }
        }
    }

    cout << cache[n-2][arr[n - 1]] << '\n';
    return 0;
}
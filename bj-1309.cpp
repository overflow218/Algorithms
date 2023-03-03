#include <iostream>
using namespace std;

int arr[100010] = {1};
int main()
{
    int n;
    cin >> n;
    arr[1] = 3;
    for(int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;
    }
    printf("%d\n", arr[n]);
    return 0;
}
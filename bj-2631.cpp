#include <iostream>
using namespace std;

int arr[300];
int cache[300] = {0};
int n;
int find(int idx)
{
    int &ret = cache[idx];
    if(ret != 0) return ret;
    ret = 1;
    for(int next = idx + 1; next <= n; next++)
    {
        if(arr[idx] < arr[next])
        {
            ret = max(ret, 1 + find(next));
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    arr[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int fixed = find(0) - 1;
    printf("%d\n", n - fixed);
    return 0;
}
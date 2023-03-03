#include <iostream>
using namespace std;

int n;
int arr[1001];
int cache[1001] = {0};

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
    for(int i = 1; i <= n ;i++)
    {
        cin >> arr[i];
    }
    printf("%d\n", find(0) - 1);
    return 0;
}

/*
8
1 6 2 5 7 3 5 6
*/
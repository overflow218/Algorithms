#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1, -1);
    vector<int> vec = {-1};
    vector<int> idx = {0};
    vector<int> prev(n + 1, -1);

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int last_idx = -1;
    for(int i = 1; i <= n; i++)
    {
        if(vec.back() < arr[i])
        {
            vec.push_back(arr[i]);
            prev[i] = idx.back();
            idx.push_back(i);
            last_idx = i;
        } else 
        {
            auto it = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            vec[it] = arr[i];
            idx[it] = i;
            prev[i] = idx[it - 1];
        }
    }

    int ans = vec.size() - 1;
    printf("%d\n", ans);
    deque<int> lis;

    while(last_idx != 0)
    {
        lis.push_front(arr[last_idx]);
        last_idx = prev[last_idx];
    }

    for(int i = 0; i < ans; i++)
    {
        printf("%d ", lis[i]);
    }
    printf("\n");
    return 0;
}

/*
7

1 6 2 4 5 3 7
5
1 2 3 5 7 

*/
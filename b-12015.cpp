#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
    }

    vector<int> lis = {vec[0]};
    for(int i = 1; i < n; i++)
    {
        if(lis.back() < vec[i])
        {
            lis.push_back(vec[i]);
        } else 
        {
            vector<int> :: iterator it = lower_bound(lis.begin(), lis.end(), vec[i]);
            int idx = it - lis.begin();
            lis[idx] = vec[i];
        }
    }
    printf("%lu\n", lis.size());
    return 0;
}
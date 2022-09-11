#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int c, n, tmp;
int arr[500] = {0};
vector<int> vec;

int main()
{
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d", &n);
        vec.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if(vec.empty() || vec.back() < tmp)
            {
                vec.push_back(tmp);
            } else 
            {
                vec[lower_bound(vec.begin(), vec.end(), tmp) - vec.begin()] = tmp;
            }
        }
        printf("%d\n", vec.size());
    }
    return 0;
}
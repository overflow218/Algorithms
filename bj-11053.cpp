#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> ans;
int main()
{
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    for(int i = 0; i < n; i++)
    {
        vector<int> :: iterator it = lower_bound(ans.begin(), ans.end(), vec[i]);
        if(it == ans.end())
        {
            ans.push_back(vec[i]);
        } else 
        {
            ans[it - ans.begin()] = vec[i];
        }
    }
    printf("%d\n", (int)ans.size());
    return 0;
}
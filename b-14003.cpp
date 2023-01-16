#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(vector<int> & check, vector<int> &vec, int lis)
{
    vector<int> ans;
    int limit = (int) vec.size();
    int target = lis;

    for(int i = limit - 1; i >= 0; i--)
    {
        if(check[i] == target)
        {
            ans.push_back(vec[i]);
            target--;
            if(target == 0) break;
        }
    }

    for(int i = lis - 1; i >= 0; i--)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
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
    vector<int> check = {1};
    for(int i = 1; i < n; i++)
    {
        if(lis.back() < vec[i])
        {
            lis.push_back(vec[i]);
            check.push_back(lis.size());
        } else 
        {
            vector<int> :: iterator it = lower_bound(lis.begin(), lis.end(), vec[i]);
            int idx = it - lis.begin();
            lis[idx] = vec[i];
            check.push_back(idx + 1);
        }
    }

    printf("%lu\n", lis.size());
    find(check, vec, (int)lis.size());
    return 0;
}
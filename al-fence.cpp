#include <iostream>
#include <cstdio>
using namespace std;

int fence[20000] = {0};

int find(int left, int right)
{
    if(left == right) return fence[left];
    int mid = (left + right) / 2;
    int ans = max(find(left, mid), find(mid + 1, right));
    int l = mid, r = mid + 1;
    int height = min(fence[l], fence[r]);
    ans = max(ans, 2 * height);
    while(left < l || r < right)
    {
        if(left < l && (r == right || fence[l - 1] >= fence[r + 1]))
        {
            height = min(height, fence[--l]);
        } else 
        {
            height = min(height, fence[++r]);
        }
        ans = max(ans, (r - l + 1) * height);
    }
    return ans;
}

int main()
{
    int c, n;
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &fence[i]);
        }
        printf("%d\n", find(0, n - 1));
    }
    return 0;
}
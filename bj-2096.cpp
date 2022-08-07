#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, big0 = 0, big1 = 0, big2 = 0, small0 = 0, small1 = 0, small2 = 0, arr1, arr2, arr0;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int tmp_big0, tmp_big1, tmp_big2, tmp_small0, tmp_small1, tmp_small2;
        scanf("%d %d %d", &arr0, &arr1, &arr2);

        tmp_big0 = max(big0, big1) + arr0;
        tmp_big1 = max(big2, (max(big0, big1))) + arr1;
        tmp_big2 = max(big2, big1) + arr2;

        tmp_small0 = min(small0, small1) + arr0;
        tmp_small1 = min(small2, (min(small0, small1))) + arr1;
        tmp_small2 = min(small2, small1) + arr2;

        big0 = tmp_big0;
        big1 = tmp_big1;
        big2 = tmp_big2;

        small0 = tmp_small0;
        small1 = tmp_small1;
        small2 = tmp_small2;
    }

    printf("%d %d\n", max(big2, (max(big0, big1))), min(small2, (min(small0, small1))));
    return 0;
}
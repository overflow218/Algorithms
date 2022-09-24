#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, s;
int arr[100000];
int pSum[100000];

int find(int start, int end, int limit)
{
    int sum = start == 0 ? pSum[end] : pSum[end] - pSum[start - 1];
    // 합이 모자란 경우 
    if(sum < s)
    {
        int next = (end + limit) / 2;
        return next == end ? n : find(start, next, limit);
    } 
    // 합이 s 이상인 경우 -> 더 작은 수로 만들수 있는지 체크
    else {
        int ret = end - start + 1;
        int next = (start + end) / 2;
        return next == end ? ret : min(ret, find(start, next, end));
    }
}

int main()
{
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        pSum[i] = i == 0 ? arr[i] : pSum[i - 1] + arr[i];
    }  
    // 불가능한 경우
    if(pSum[n - 1] < s)
    {
        printf("0\n");
        return 0;
    }
    int ans = n;
    for(int start = 0; start < n; start++)
    {
        ans = min(ans, find(start, n - 1, n - 1));
    }
    printf("%d\n", ans);
    return 0;
}
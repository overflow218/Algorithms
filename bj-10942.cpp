#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, s, e;
int arr[2001];
int isPalindrome[2001][2001];
int find(int start, int end)
{
    if(start >= end) return 1;
    int & ret = isPalindrome[start][end];
    if(ret != -1) return ret;
    return ret = arr[start] == arr[end] && find(start + 1, end - 1);
}

int main()
{
    scanf("%d", &n);
    memset(isPalindrome, -1, sizeof(isPalindrome));
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);
        printf("%d\n", find(s, e));
    }
    return 0;
}
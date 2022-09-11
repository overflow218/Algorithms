#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// cache[i] = i번 인덱스부터 시작하는 원주율 최솟값
int cache[10000] = {0};
int n;
char str[10001] = {0};

// [start, start + cnt - 1] 까지의 난이도를 반환한다
int difficulty(int start, int cnt)
{
    // 번갈아가면서 나오는지 확인
    bool isAlternating = true;
    for(int i = 0; i < cnt; i++)
    {
        if(str[start + i] != str[start + (i % 2)]) isAlternating = false;
    }
    if(isAlternating)
    {
        // case 1
        if(str[start] == str[start + 1])
        {
            return 1;
        }
        //case 3
        return 4;
    }
    // 등차수열인지 확인
    bool isArithmetic = true;
    for(int i = 1; i < cnt; i++)
    {
        if(str[start + i] - str[start + i - 1] != str[start + 1] - str[start]) isArithmetic = false;
    }
    if(isArithmetic)
    {
        return abs(str[start + 1] - str[start]) == 1 ? 2 : 5;
    }
    return 10;
}

int dp(int idx)
{
    // basecase 끝까지 간경우
    if(idx == n) return 0;
    int & ret = cache[idx];
    if(ret) return ret;
    ret = 987654321;
    for(int i = 3; i <= 5; i++)
    {
        if(idx + i <= n)
        {
            ret = min(ret, difficulty(idx, i) + dp(idx + i));
        }
    }
    return ret;
}

int main()
{
    int c;
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%s", str);
        n = strlen(str);
        memset(cache, 0, sizeof(cache));
        printf("%d\n", dp(0));
    }
    return 0;
}
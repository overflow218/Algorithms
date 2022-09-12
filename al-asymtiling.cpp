#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
전체적인 방향성 이거 고딩때 경우의 수 세는거랑 비슷함. 
전체 경우의 수 = 조건 만족하는 경우 + 조건 안 만족하는 경우 
1. 여사건을 구하는 경우 
문제에 대입하자면 
전체 타일링 방법의 수 = 대칭인 경우 + 비대칭인 경우 
비대칭인 경우 = 전체 타일링 방법의 수 - 대칭인 경우 
전체 타일링의 방법은 이전에 풀었던 tiling 문제랑 똑같음. 
비대칭보다는 대칭이 세기 쉬우니까 문제에서 비대칭을 구하라고 한거겠지?

n이 홀수인 경우 
1. 가운데 하나 빼고 반띵한 경우의 수 -> (n - 1) / 2 
n이 짝수인 경우 
1. 그냥 반띵한 경우 -> n/2
2. 가운데 옆으로 2칸짜리 박아놓고 반띵한 경우 -> (n - 2) / 2

2. 직접 비대칭한 방법 세는 경우 
책의 경우 참고해서 해결 -> 난 1번으로 풀거임 저게 편하거덩
*/
const int MOD = 1000000007;

int tiling[101] = {1, 1, 2};
int asymTiling[101] = {0};

int findSym(int n)
{
    int & ret = tiling[n];
    if(ret) return ret;
    return ret = (findSym(n - 1) + findSym(n - 2)) % MOD;
}

int findAsym(int n)
{
    int & ret = asymTiling[n];
    if(ret) return ret;
    // n = 홀수
    if(n % 2)
    {
        return ret = (findSym(n) - findSym((n - 1) / 2) + MOD) % MOD;
    }
    // n = 짝수
    ret = findSym(n);
    ret = (ret - findSym(n / 2) + MOD) % MOD;
    return ret = (ret - findSym((n - 2) / 2) + MOD) % MOD;
}

int main()
{
    int c, n;
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d", &n);
        printf("%d\n", findAsym(n));
    }    
    return 0;
}
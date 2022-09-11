#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>
using namespace std;

const long long NEW_INF = numeric_limits<long long>::min();
int c, n, m;
int A[100] = {0};
int B[100] = {0};
// 맨앞에 -1, -1 이 있다고 생각하고 구해줄 것이기 때문에 
// i,j에 대해서는 cache[i + 1][j + 1]을 살펴본다 
// 0: 아직 안구함. 0 아닌경우: 구함. 
int cache[101][101] = {0};

int jlis(int x, int y)
{
    int & ret = cache[x + 1][y + 1];
    // 이미 구한경우 바로 리턴. 
    if(ret) return ret;
    long long nextA = x == -1 ? NEW_INF : A[x];
    long long nextB = y == -1 ? NEW_INF : B[y];
    long long next = max(nextA, nextB);
    // 가정 조건이 A[x] != B[y] 이거나 x = y = -1 이라는 상황임. 
    // 그래서 마지막에 답 구한다음에 앞에 -1 포함시킨거를 빼줄거임.
    ret = 2;
    for(int i = x + 1; i < n; i++)
    {
        if(next < A[i])
        {
            ret = max(ret, 1 + jlis(i, y));
        }
    }
    for(int i = y + 1; i < m; i++)
    {
        if(next < B[i])
        {
            ret = max(ret, 1 + jlis(x, i));
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d %d", &n, &m);
        memset(cache, 0, sizeof(cache));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &B[i]);
        }
        printf("%d\n", jlis(-1, -1) - 2);
    }
    return 0;
}
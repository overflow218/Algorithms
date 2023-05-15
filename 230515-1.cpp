#include <string>
#include <vector>
using namespace std;

// counter[i][0] = i번째 단계의 전체 수 개수
// counter[i][1] = i번째 단계의 1개수 
long long counter[21][2];
int find(int n, long long l, long long r)
{
    int L = l, R = r;
    // 전체 범위 다 포함하는 경우
    if(l == 1ll && r == counter[n][0])
    {
        printf("n: %d, l:%d, r: %d, ans: %d\n", n, L, R, counter[n][1]);
        return counter[n][1];
    }
    // n = 1로 떨어진 경우
    if(n == 1)
    {
        int ans = r - l + 1;
        if(l <= 3 && 3 <= r) ans--;
        printf("n: %d, l:%d, r: %d, ans: %d\n", n, L, R, ans);
        return ans;
    }
    
    // recursive case
    long long cnt = 0;
    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        if(l > r) break;
        
        if(l <= cnt + counter[n - 1][0])
        {
            long long start = l - cnt;
            long long end = min(r - cnt, counter[n - 1][0]);
            if(i != 2) ans += find(n - 1, start, end);
            cnt += counter[n - 1][0];
            l = cnt + 1;
        }
    }
    printf("n: %d, l:%d, r: %d, ans: %d\n", n, L, R, ans);
    return ans;
}

int solution(int n, long long l, long long r) {
    counter[0][0] = 1;
    counter[0][1] = 1;
    for(int i = 1; i <= 20; i++)
    {
        counter[i][0] = 5ll * counter[i - 1][0];
        counter[i][1] = 4ll * counter[i - 1][1];
    }
    return find(n, l, r);
}
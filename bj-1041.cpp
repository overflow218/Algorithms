#include <iostream>
#include <vector>
using namespace std;

bool isOpposite(int a, int b)
{
    if(b < a) return isOpposite(b, a);
    if((a == 0 && b == 5) || (a == 1 && b == 4) || (a == 2 && b == 3)) return true;
    return false;
}

int main()
{
/*
1만 예외 케이스 
n >= 2 인 경우
1면만 보이는 칸수 -> 4 * (n - 2) * (n - 1)  + (n-2) ^ 2
2면 보이는 칸수 -> 8 * n - 12
3면 보이는 칸수 -> 4개 
*/    
    long long n;
    scanf("%lld", &n);
    vector<long long> dice(6);
    for(int i = 0; i < 6; i++)
    {
        scanf("%lld", &dice[i]);
    }
    long long one_side = 987654321, two_side = 987654321, three_side = 987654321;
    for(int i = 0; i < 6; i++)
    {
        one_side = min(one_side, dice[i]);
    }

    for(int i = 0; i < 6; i++)
    {
        for(int j = i + 1; j < 6; j++)
        {
            if(!isOpposite(i, j))
            {
                two_side = min(two_side, dice[i] + dice[j]);
            }
        }
    }

    for(int i = 0; i < 6; i++)
    {
        for(int j = i + 1; j < 6; j++)
        {
            for(int k = j + 1; k < 6; k++)
            {
                if(!isOpposite(i, j) && !isOpposite(i, k) && !isOpposite(j, k))
                {
                    three_side = min(three_side, dice[i] + dice[j] + dice[k]);
                }
            }
        }
    }
    long long ans;
    if(n == 1)
    {
        long long big = 0;
        for(int i = 0; i < 6; i++)
        {
            big = max(big, dice[i]);
            ans += dice[i];
        }
        ans -= big;
    } else 
    {
        long long one = 4ll * (n - 2ll) * (n - 1ll) + (n - 2ll) * (n - 2ll);
        long long two = 8ll * n - 12ll;
        long long triple = 4ll;
        one *= one_side;
        two *= two_side;
        triple *= three_side;
        ans = one + two + triple;
    }
    printf("%lld\n", ans);
    return 0;
}
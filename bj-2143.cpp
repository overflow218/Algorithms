#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

/*
보면은 각 배열에서 나올수 있는 부분합의 경우의 수는 최대 O(n^2)임. 
n = 1000이니까 각각 1백만개 정도임. 
이거 백만개씩 만드는건 부분합 이용하면 그냥 이중루프 한번 돌면됨. -> O(n^2)
A 혼자 만들수 있는개수 + B 혼자 만들 수 있는 개수 + 합쳐서 만들 수 있는 개수 
map 이용하면 앞의 2항은 상수시간이고 뒤에거는 O(nlogn)일듯. 
그러면 2초안에 충분히 가능해보임. 
*/

int arr1[1000], arr2[1000], pSum1[1000], pSum2[1000];
map<int, int> A;
map<int, int> B;

int t, n, m;

int main()
{
    scanf("%d %d", &t, &n);    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pSum1[i]);
        if(i > 0)
        {
            pSum1[i] += pSum1[i - 1];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = i == 0 ? pSum1[j] : pSum1[j] - pSum1[i - 1];
            A[sum]++;
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &pSum2[i]);
        if(i > 0)
        {
            pSum2[i] += pSum2[i - 1];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = i; j < m; j++)
        {
            int sum = i == 0 ? pSum2[j] : pSum2[j] - pSum2[i - 1];
            B[sum]++;
        }
    }

    long long ans = 0;
    for(auto it = A.begin(); it != A.end(); it++)
    {
        ans += (long long)it -> second * (long long)B[t - (it -> first)];
    }

    printf("%lld\n", ans);
    return 0;
}
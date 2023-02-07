#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int coin[100];
int cache[10001] = {1};

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = coin[i]; j <= k; j++)
        {
            cache[j] += cache[j - coin[i]];
        }
    }
    printf("%d\n", cache[k]);
    return 0;
}
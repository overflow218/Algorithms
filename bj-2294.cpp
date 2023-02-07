#include <iostream>
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
            if(cache[j - coin[i]] > 0)
            {
                if(cache[j] == 0)
                {
                    cache[j] = 1 + cache[j - coin[i]];
                } else 
                {
                    cache[j] = min(cache[j], 1 + cache[j - coin[i]]);
                }
            }
        }
    }
    printf("%d\n", cache[k] - 1 > 0 ? cache[k] - 1 : -1);
    return 0;
}
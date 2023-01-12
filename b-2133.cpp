#include <iostream>
using namespace std;

int main()
{
    int cache[31] = {1, 0, 3};
    int n;
    scanf("%d", &n);
    for(int i = 4; i <= n; i += 2)
    {
        cache[i] = 3 * cache[i - 2];
        for(int j = i - 4; j >= 0; j -= 2)
        {
            cache[i] += 2 * cache[j];
        }
    }

    printf("%d\n", cache[n]);
    return 0;
}
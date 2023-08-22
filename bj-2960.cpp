#include <iostream>
using namespace std;

bool isDeleted[1001] = {false};
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 2; i <= n; i++)
    {
        if(isDeleted[i]) continue;
        for(int j = 1; i * j <= n; j++)
        {
            if(isDeleted[i * j]) continue;
            isDeleted[i * j] = true;
            k--;
            if(k == 0)
            {
                printf("%d\n", i * j);
                break;
            }
        }
    }

    return 0;
}
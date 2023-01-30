#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> scale (n, 0);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &scale[i]);
    }

    int sum = 0;
    sort(scale.begin(), scale.end());
    for(int i = 0; i < n; i++)
    {
        if(sum + 1 >= scale[i])
        {
            sum += scale[i];
        } else 
        {
            break;
        }
    }

    printf("%d\n", sum + 1);
    return 0;
}
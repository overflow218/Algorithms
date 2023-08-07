#include <iostream>
using namespace std;

int arr[10000];
int pSum[10000];
int main()
{
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        pSum[i] = i == 0 ? arr[i] : arr[i] + pSum[i - 1];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int check = i == 0 ? pSum[j] : pSum[j] - pSum[i - 1];
            if(check == m) cnt++;
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}
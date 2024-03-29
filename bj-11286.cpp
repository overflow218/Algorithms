#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<pair<int, int> > pq;

int main()
{
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(x == 0)
        {
            if(pq.empty())
            {
                printf("0\n");
            } else 
            {
                printf("%d\n", -pq.top().second);
                pq.pop();
            }
        } else 
        {
            pq.push(make_pair(-abs(x), -x));
        }
    }
    return 0;
}
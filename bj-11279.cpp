#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main()
{
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if(tmp)
        {
            pq.push(tmp);
        } else 
        {
            printf("%d\n", pq.empty() ? 0 : pq.top());
            if(!pq.empty()) pq.pop();
        }
    }
}
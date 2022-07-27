#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

multiset<int> heap;

int main()
{
    int t, k, n;
    char cmd[10];
    scanf("%d", &t);
    
    for(int h = 0; h < t; h++)
    {
        scanf("%d", &k);
        heap.clear();
        for(int i = 0; i < k; i++)
        {
            scanf("%s %d", cmd, &n);
            if(cmd[0] == 'I')
            {
                heap.insert(n);
            } else 
            {
                // 최대값 삭제
                if(n == 1)
                {
                    if(!heap.empty())
                    {
                        heap.erase(--heap.end());
                    }
                } else 
                {
                    if(!heap.empty())
                    {
                        heap.erase(heap.begin());
                    }
                }
            }
        }
        if(heap.empty())
        {
            printf("EMPTY\n");
        } else 
        {
            printf("%d %d\n", *heap.rbegin(), *heap.begin());
        }
    }
    return 0;
}
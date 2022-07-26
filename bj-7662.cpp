#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

map<int, int> check;
priority_queue<int> maxHeap;
priority_queue<int> minHeap;

int main()
{
    int t, k, n;
    char cmd[10];
    scanf("%d", &t);
    
    for(int h = 0; h < t; h++)
    {
        scanf("%d", &k);
        int cnt = 0;
        check.clear();  
        maxHeap = priority_queue<int>();
        minHeap = priority_queue<int>();
        for(int i = 0; i < k; i++)
        {
            scanf("%s %d", cmd, &n);
            if(cmd[0] == 'I')
            {
                cnt++;
                maxHeap.push(n);
                minHeap.push(-n);
                if(check.find(n) != check.end())
                {
                    check[n]++;
                } else 
                {
                    check[n] = 1;
                }
            } else 
            {
                // 최대값 삭제
                if(n == 1)
                {
                    while(!maxHeap.empty())
                    {
                        int tmp = maxHeap.top();
                        maxHeap.pop();
                        if(check[tmp] > 0)
                        {
                            cnt--;
                            check[tmp]--;
                            break;
                        }
                    }
                } else 
                {
                    while(!minHeap.empty())
                    {
                        int tmp = -minHeap.top();
                        minHeap.pop();
                        if(check[tmp] > 0)
                        {
                            cnt--;
                            check[tmp]--;
                            break;
                        }
                    }
                }
            }
        }
        if(cnt <= 0)
        {
            printf("EMPTY\n");
            continue;
        }
        int big, small;
        while(!maxHeap.empty())
        {
            int tmp = maxHeap.top();
            maxHeap.pop();
            if(check[tmp] > 0)
            {
                big = tmp;
                break;
            }
        }
        while(!minHeap.empty())
        {
            int tmp = -minHeap.top();
            minHeap.pop();
            if(check[tmp] > 0)
            {
                small = tmp;
                break;
            }
        }
        printf("%d %d\n", big, small);
    }
    return 0;
}
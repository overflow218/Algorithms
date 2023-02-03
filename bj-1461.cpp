#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m, tmp;
    scanf("%d %d", &n, &m);
    priority_queue<int> pos, neg;
    int pos_max = 0, neg_max = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if(tmp > 0)
        {
            pos.push(-tmp);
            pos_max = max(pos_max, tmp);
        } else if(tmp < 0)
        {
            neg.push(tmp);
            neg_max = max(neg_max, -tmp);
        }
    }
    int ans = 0;
    // pos거 먼저 빼고 neg거 뺀다
    if(pos_max < neg_max)
    {
        while(!pos.empty())
        {
            int tmp = 0;
            for(int i = 0; i < m; i++)
            {
                tmp = -pos.top();
                pos.pop();
                if(pos.size() % m == 0) break;
            }
            ans += tmp * 2;
        }
        while(!neg.empty())
        {
            int tmp = 0;
            bool isLast = false;
            for(int i = 0; i < m; i++)
            {
                tmp = -neg.top();
                neg.pop();
                if(neg.size() % m == 0)
                {
                    isLast = neg.empty();
                    break;
                } 
            }
            ans += isLast ? tmp : tmp * 2;
        }
    } else 
    {
        while(!neg.empty())
        {
            int tmp = 0;
            for(int i = 0; i < m; i++)
            {
                tmp = -neg.top();
                neg.pop();
                if(neg.size() % m == 0) break;
            }
            ans += tmp * 2;
        }
        while(!pos.empty())
        {
            int tmp = 0;
            bool isLast = false;
            for(int i = 0; i < m; i++)
            {
                tmp = -pos.top();
                pos.pop();
                if(pos.size() % m == 0)
                {
                    isLast = pos.empty();
                    break;
                } 
            }
            ans += isLast ? tmp : tmp * 2;
        }
    }

    printf("%d\n", ans);
    return 0;
}
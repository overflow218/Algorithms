#include<cstdio>
#include <iostream>
#include <queue>
using namespace std;
bool isVisited[100001] = {false};

int main()
{
    int n, k;
    queue<pair<int, int> > q = queue<pair<int, int> >();
    scanf("%d %d", &n, &k);
    q.push(make_pair(n, 0));
    
    while(!q.empty())
    {
        pair<int, int> x = q.front();
        int current = x.first, cnt = x.second;
        q.pop();
        if(current == k)
        {
            printf("%d\n", cnt);
            return 0;
        } else if(current < 0 || current > 100000)
        {
            continue;
        }
        if(!isVisited[current])
        {
            isVisited[current] = true;
            q.push(make_pair(current * 2, cnt + 1));
            q.push(make_pair(current + 1, cnt + 1));
            q.push(make_pair(current - 1, cnt + 1));
        }
    }
    return 0;
}
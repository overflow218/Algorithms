#include <iostream>
#include <queue>
using namespace std;

bool isVisited[1000001] = {false};

queue<int> q;
int main()
{
    int F, S, G, U, D, ans = 0;
    cin >> F >> S >> G >> U >> D;
    
    q.push(S);
    while(!q.empty())
    {
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            int x = q.front();
            q.pop();
            if(x == G)
            {
                printf("%d\n", ans);
                return 0;
            }
            if(x <= 0 || x > F) continue;
            if(isVisited[x]) continue;
            isVisited[x] = true;
            q.push(x + U);
            q.push(x - D);
        }
        ans++;
    }
    
    printf("use the stairs\n");
    return 0;
}
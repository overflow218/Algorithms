#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

map<int, int> radder;
map<int, int> snake;
queue<pair<int, int> > q;

int visited[101] = {0};

int main()
{
    int n, m, from, to;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &from, &to);
        radder[from] = to;
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &from, &to);
        snake[from] = to;
    }
    q.push(make_pair(1, 0));
    int ans = 100000;
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if(current.first == 100)
        {
            ans = min(ans, current.second);
            continue;
        }
        if(current.first > 100) continue;
        if(visited[current.first] != 0 && visited[current.first] <= current.second) continue;
        visited[current.first] = current.second;

        if(radder.find(current.first) != radder.end())
        {
            q.push(make_pair(radder[current.first], current.second));
        } else if(snake.find(current.first) != snake.end())
        {
            q.push(make_pair(snake[current.first], current.second));
        } else 
        {
            for(int i = 1; i <= 6; i++)
            {
                q.push(make_pair(current.first + i, current.second + 1));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
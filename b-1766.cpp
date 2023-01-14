#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// (우선순위, 노드)
priority_queue<pair<long long, long long>> pq;
const long long INF = 32000;
int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    // 요 안에서도 입력이 들어오는 순서를 고려해줘야되네 ㄷㄷ..
    vector<vector<int>> preSolve(n + 1);
    vector<long long> priority(n + 1, 0);
    vector<bool> isVisited(n + 1);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        preSolve[a].push_back(b);
        priority[b] += INF;
    }

    for(int i = 1; i <= n; i++)
    {
        priority[i] = priority[i] + ((long long)i);
        pq.push(make_pair(-priority[i], i));
        // printf("%d 의 우선순위: %lld\n", i, priority[i] + i);
    }

    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if(isVisited[node]) continue;
        isVisited[node] = true;
        printf("%d ", node);
        for(int i = 0; i < preSolve[node].size(); i++)
        {
            int next = preSolve[node][i];
            // printf("%d 의 우선순위 갱신전: %lld\n", next, priority[next]);
            priority[next] -= INF;
            // printf("%d 의 우선순위 갱신후: %lld\n", next, priority[next]);
            pq.push(make_pair(-priority[next], next));
        }
    }
    printf("\n");
    return 0;
}
/*
6 4
6 4
6 3
4 2
3 1
*/
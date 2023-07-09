#include <iostream>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;
/*
이거 단순하게는 bfs로 해결하면 될 것 같은데
격자 밖으로 가져가야 한다는 조건이 조금 걸리네 
a1. 시작점(1, 1)에서 R까지 최단거리로 이동
a2.R에서 가장 가까운 격자를 탐색 + B로 이동
a3. B에서 도착점(n, m)으로 이동

사실 1번과 3번은 격자 크기가 크긴해도 시간안에 충분히 탐색가능함. 
그런데 2번을 효율적으로 할 방법이 뭐가 있을까?
저렇게 풀면 어렵고 생각의 방향을 바꿔보면 좋은 방법이 나오네 
b1. R이 있는 칸에서 각각 모든 칸까지의 거리를 구한다. 
b2. B가 있는 칸에서 각각 모든 칸까지의 거리를 구한다. 
위의 방법으로 하면
a1, a3는 쉽게 구하고 
a2 역시 가능한 총테두리 최대 1000개에 대해서 
R에서 해당 격자로 이동 + B에서 해당 격자로 이동 시간이 
최소가 되는 값을 찾으면 되네 그러면 끝
*/

int costA[502][502];
int costB[502][502];
char arr[502][502];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

queue<pair<int, int>> q;
void visit(bool isA)
{
    int dist = 0;
    while(!q.empty())
    {
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            pair<int, int> tmp = q.front();
            q.pop();
            int x = tmp.first, y = tmp.second;
            // 범위 벗어나거나 벽인 경우 종료
            if(x < 0 || x == n || y < 0 || y == m || arr[x][y] == 'X') continue;
            if(isA)
            {
                if(costA[x][y] != -1) continue;
                costA[x][y] = dist;
            }
            if(!isA)
            {
                if(costB[x][y] != -1) continue;;
                costB[x][y] = dist;
            }

            for(int j = 0; j < 4; j++)
            {
                q.push(make_pair(x + dx[j], y + dy[j]));
            }
        }
        dist++;
    }
}
int main() {
    int t;
    scanf("%d", &t);

    for(int test = 1; test <= t; test++)
    {
        memset(costA, -1, sizeof(costA));
        memset(costB, -1, sizeof(costB));
        scanf("%d %d", &n, &m);
        int rx, ry, bx, by;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", arr[i]);
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 'R')
                {
                    rx = i;
                    ry = j;
                }
                if(arr[i][j] == 'B')
                {
                    bx = i;
                    by = j;
                }
            }
        }

        assert(q.empty());
        q.push(make_pair(rx, ry));
        visit(true);
        assert(q.empty());
        q.push(make_pair(bx, by));
        visit(false);

        int cost1 = costA[0][0];
        int cost3 = costB[n - 1][m - 1];
        if(cost1 == -1 || cost3 == -1)
        {
            printf("#%d -1\n", test);
            continue;
        }
        int cost2 = 1000000;
        for(int i = 0; i < n; i++)
        {
            if(costA[i][0] != -1 && costB[i][0] != -1) cost2 = min(cost2, costA[i][0] + costB[i][0]);
            if(costA[i][m - 1] != -1 && costB[i][m - 1] != -1) cost2 = min(cost2, costA[i][m - 1] + costB[i][m - 1]);
        }

        for(int i = 0; i < m; i++)
        {
            if(costA[0][i] != -1 || costB[0][i] != -1) cost2 = min(cost2, costA[0][i] + costB[0][i]);
            if(costA[n - 1][i] != -1 || costB[n - 1][i] != -1) cost2 = min(cost2, costA[n - 1][i] + costB[n - 1][i]);
        }

        printf("#%d %d\n", test, cost1 + cost2 + cost3);
    }

    return 0;
}

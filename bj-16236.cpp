#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

class point{
    public:
        int x;
        int y;
        int dist;
        point(int x, int y, int dist){
            this -> x = x;
            this -> y = y;
            this -> dist = dist;
        }
};

int sea[20][20] = {0};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool isVisited[20][20] = {false};
queue<point> q;

int main()
{
    int n, sharkSize = 2, eat_cnt = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &sea[i][j]);
            if(sea[i][j] == 9)
            {
                q.push(point(i, j, 0));
                sea[i][j] = 0;
            } 
        }
    }

    while(!q.empty())
    {
        memset(isVisited, false, sizeof(isVisited));
        bool find = false;
        int tmp_dist = 1000;
        set<pair<int, int> > candidate;
        while(!q.empty())
        {
            point current = q.front();
            q.pop();
            int x = current.x, y = current.y;
            if(x < 0 || x >= n || y < 0 || y >= n || isVisited[x][y] || current.dist > tmp_dist) continue;
            isVisited[x][y] = true;
            if(sea[x][y] <= sharkSize)
            {
                if(sea[x][y] > 0 && sea[x][y] < sharkSize && current.dist <= tmp_dist)
                {
                    if(current.dist < tmp_dist) candidate.clear();
                    tmp_dist = current.dist;
                    candidate.insert(make_pair(x, y));
                }
                for(int i = 0; i < 4; i++)
                {
                    q.push(point(x + dx[i], y + dy[i], current.dist + 1));
                }
            }
        }
        if(!candidate.empty())
        {
            ans += tmp_dist;
            if(++eat_cnt == sharkSize)
            {
                sharkSize++;
                eat_cnt = 0;
            }

            pair<int, int> current = *candidate.begin();
            int x = current.first, y = current.second;
            sea[x][y] = 0;
            q = queue<point>();
            q.push(point(x, y, 0));
        }
    }
    printf("%d\n", ans);
    return 0;
}
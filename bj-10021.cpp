#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Pipe {
    int x;
    int y;
    int cost;
};

bool cmp(Pipe a, Pipe b)
{
    return a.cost < b.cost;
}

vector<Point> points;
vector<Pipe> pipes;
int root[2010];
int height[2010];

int find(int a)
{
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}

bool isUnion(int a, int b)
{
    return find(a) == find(b);
}

void make(int a, int b)
{
    a = find(a);
    b = find(b);
    if(height[a] < height[b])
    {
        root[a] = b;
        height[b] += height[a];
    } else 
    {
        root[b] = a;
        height[a] += height[b];
    }
}

int main()
{
    int n, c, x, y;
    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        Point newPoint = {x, y};
        points.push_back(newPoint);
        root[i] = i;
        height[i] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int x1 = points[i].x, y1 = points[i].y, x2 = points[j].x, y2 = points[j].y;
            int cost = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            Pipe newPipe = {i, j, cost};
            pipes.push_back(newPipe);
        }
    }

    sort(pipes.begin(), pipes.end(), cmp);

    int ans = 0, cnt = 0;

    for(const auto & p: pipes)
    {
        int a = p.x, b = p.y, cost = p.cost;
        if(cost < c) continue;
        if(cost < c || isUnion(a, b)) continue;
        ans += cost;
        cnt++;
        make(a, b);
        if(cnt == n - 1) break;
    }

    ans = cnt == n - 1 ? ans : -1;
    cout << ans <<'\n';
    return 0;
}
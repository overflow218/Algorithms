#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// i번째 일에 j번 높이에 있을때 m일 안에 우물 끝까지 도달할 확률!
double cache[1004][1004] = {0};
bool isVisited[1004][1004] = {0};
int c, n, m;

double snail(int day, int height)
{
    // 책의 풀이 -> 이렇게 하면 cache 범위가 늘어나야함. 
    // if(day == m) return height >= n ? 1 : 0;
    if(day > m) return 0;
    if(height >= n) return 1;
    double & ret = cache[day][height];
    if(isVisited[day][height]) return ret;
    isVisited[day][height] = true;
    return ret = snail(day + 1, height + 2) * 0.75 + snail(day + 1, height + 1) * 0.25;
}

int main()
{
    scanf("%d", &c);
    for(int i = 0; i < c; i++)
    {
        scanf("%d %d", &n, &m);
        memset(cache, 0, sizeof(cache));
        memset(isVisited, 0, sizeof(isVisited));
        printf("%.9f\n", snail(0, 0));
    }
    return 0;
}
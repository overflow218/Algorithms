#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int c, n, d, p, t, q;
// isConnected[i][j] = i번 마을과 j번 마을이 연결되어있으면 참, 아니면 거짓
vector< vector<int> > isConnected;
// cache[day][idx] = day일차에 idx번 마을에 있을 확률
double cache[101][50];
bool isVisited[101][50];

double find(int day, int idx)
{
    if(day == 0) return idx == p ? 1 : 0;
    double & ret = cache[day][idx];
    if(isVisited[day][idx]) return ret;
    isVisited[day][idx] = true;
    for(int prev = 0; prev < (int)isConnected[idx].size(); prev++)
    {
        int next = isConnected[idx][prev];
        ret += find(day - 1, next) / isConnected[next].size();
    }
    return ret;
}

int main()
{
    scanf("%d", &c);
    for(int test = 0; test < c; test++)
    {
        scanf("%d %d %d", &n, &d, &p);
        isConnected.clear();
        memset(cache, 0, sizeof(cache));
        memset(isVisited, 0, sizeof(isVisited));

        for(int i = 0; i < n; i++)
        {
            vector<int> vec;
            int tmp;
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &tmp);
                if(tmp) vec.push_back(j);
            }
            isConnected.push_back(vec);
        }
        scanf("%d", &t);
        for(int i = 0; i < t; i++)
        {
            scanf("%d", &q);
            printf("%.10f\n", find(d, q));
        }
    }
    return 0;
}
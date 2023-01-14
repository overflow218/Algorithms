#include <iostream>
using namespace std;

int cost[100001][5][5] = {0};
int order[100001] = {0};
int idx = 0;

int distance(int from, int to)
{
    if(from == 0) return 2;
    if(from == to) return 1;
    if(abs(from - to) == 2) return 4;
    return 3;
}

int find(int stage, int left, int right)
{
    if(stage == idx) return 0;
    int &ret= cost[stage][left][right];
    if(ret != 0) return ret;
    return ret = min(distance(left, order[stage]) + find(stage + 1, order[stage], right), distance(right, order[stage]) + find(stage + 1, left, order[stage]));
}

int main()
{
    int next;
    scanf("%d", &next);
    while(next != 0)
    {
        order[idx++] = next;
        scanf("%d", &next);
    }
    printf("%d\n", find(0, 0, 0));
    return 0;
}
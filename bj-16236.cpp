#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int sea[20][20] = {0};
set<pair<int, int> > fish;

int main()
{
    int n, sharkX, sharkY, sharkSize;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &sea[i][j]);
            if(sea[i][j] == 9)
            {
                sharkX = i;
                sharkY = j;
                sharkSize = 2;
            }
            else if(sea[i][j] > 0)
            {
                fish.insert(make_pair(i, j));
            }
        }
    }

    int ans = 0, tmp = 1000;
    for(auto f: fish)
    {
        if(sea[f.first][f.second] <)
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

bool isGood = false;
void check(int idx, vector<pair<int, int>> &stage, vector<bool> & isVisited)
{
    if(idx == stage.size() - 1)
    {
        isGood = true;
        return;
    }
    if(isVisited[idx]) return;
    isVisited[idx] = true;
    for(int i = 0; i < stage.size(); i++)
    {
        if(isVisited[i]) continue;
        int diff = abs(stage[idx].first - stage[i].first) + abs(stage[idx].second - stage[i].second);
        if(diff <= 1000)
        {
            check(i, stage, isVisited);
        }
    }
}

int main()
{
    int t, n;
    cin >> t;
    for(int it = 0; it < t; it++)
    {
        cin >> n;
        int a, b;
        vector<pair<int, int>> stage;
        vector<bool> isVisited(n + 2, false);
        for(int i = 0; i < n + 2; i++)
        {
            cin >> a >> b;
            stage.push_back(make_pair(a, b));
        }
        isGood = false;
        check(0, stage, isVisited);
        if(isGood)
        {
            printf("happy\n");
        } else 
        {
            printf("sad\n");
        }
    }

    return 0;
}
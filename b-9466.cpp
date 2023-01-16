#include <iostream>
#include <vector>
using namespace std;

// 매칭 1, 불가능 0, 아직모름 -1
int find(int node, vector<int>& wanted, vector<bool> &isVisited, vector<int> &isMatched)
{
    if(isVisited[node])
    {
        if(isMatched[node] == -1)
        {
            return 1;
        }
        return 0;
    }
    isVisited[node] = true;
    return isMatched[node] = find(wanted[node], wanted, isVisited, isMatched);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for(int k = 0; k < t; k++)
    {
        scanf("%d", &n);
        vector<bool> isVisited(n + 1, false);
        vector<int> isMatched(n + 1, -1);
        vector<int> wanted(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &wanted[i]);
            if(i == wanted[i])
            {
                isVisited[i] = true;
                isMatched[i] = 1;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            if(!isVisited[i])
            {
                isMatched[i] = find(i, wanted, isVisited, isMatched);
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!isMatched[i]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
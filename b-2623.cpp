#include <iostream>
#include <vector>
using namespace std;

bool isDone[1001] = {false};
bool isVisited[1001] = {false};
bool isPossible = true;
vector<int> ans;

void find(int idx, vector<vector<int>> &next)
{
    if(isDone[idx]) return;
    if(isVisited[idx])
    {
        isPossible = false;
        return;
    }
    isVisited[idx] = true;
    for(int i = 0; i < next[idx].size(); i++)
    {
        find(next[idx][i], next);
    }
    ans.push_back(idx);
    isDone[idx] = true;
}
int main()
{
    int n, m, k, tmp;
    scanf("%d %d", &n, &m);
    vector<vector<int>> next(n + 1);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &k);
        vector<int> vec;
        for(int j = 0;j < k; j++)
        {
            scanf("%d", &tmp);
            vec.push_back(tmp);
        }
        for(int j = 0; j < k - 1; j++)
        {
            next[vec[j]].push_back(vec[j + 1]);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!isDone[i])
        {
            find(i, next);
        }
        if(!isPossible)
        {
            printf("0\n");
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d\n", ans[n - 1 -i]);
    }
    return 0;
}
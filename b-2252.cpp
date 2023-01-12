#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void visit(int idx, vector<vector<int>>& option, vector<bool> &isVisited)
{
    if(isVisited[idx]) return;
    isVisited[idx] = true;
    for(int i = 0; i < option[idx].size(); i++)
    {
        visit(option[idx][i], option, isVisited);
    }
    ans.push_back(idx);
}

int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<vector<int>> option(n + 1);
    vector<bool> isVisited(n + 1, false);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        option[a].push_back(b);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!isVisited[i]) visit(i, option, isVisited);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
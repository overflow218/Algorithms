#include <iostream>
#include <vector>
using namespace std;

int n, m, wall = 3, virus = 0, ans = 0;
vector<pair<int, int>> space;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void disperse(int x, int y, vector<vector<int>>& check,vector<bool> & isVisited)
{
    if(x < 0 || x == n || y < 0 || y == m || isVisited[x * m + y] || check[x][y] == 1) return;
    isVisited[x * m + y] = true;
    virus++;
    for(int i = 0; i < 4; i++)
    {
        disperse(x + dx[i], y + dy[i], check, isVisited);
    }
}

void find(int idx, vector<int> &chosen, vector<vector<int>>& lab)
{
    if(chosen.size() == 3)
    {
        vector<vector<int>> check(lab.begin(), lab.end());
        vector<bool> isVisited(n * m, false);
        virus = 0;

        check[space[chosen[0]].first][space[chosen[0]].second] = 1;
        check[space[chosen[1]].first][space[chosen[1]].second] = 1;
        check[space[chosen[2]].first][space[chosen[2]].second] = 1;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(check[i][j] == 2 && !isVisited[i * m + j])
                {
                    disperse(i, j, check, isVisited);
                }
            }
        }
        ans = max(ans, n * m - wall - virus);
        return;
    }
    if(idx == space.size()) return;
    for(int i = idx; i < space.size(); i++)
    {
        chosen.push_back(i);
        find(i + 1, chosen, lab);
        chosen.pop_back();
    }
}

int main()
{
    int tmp;
    scanf("%d %d", &n, &m);
    vector<vector<int>> lab(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            lab[i].push_back(tmp);
            if(tmp == 1)
            {
                wall++;
            } else if(tmp == 0)
            {
                space.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> chosen;
    find(0, chosen, lab);

    printf("%d\n", ans);
    return 0;
}
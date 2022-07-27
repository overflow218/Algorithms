#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

multiset<int> apartment;
int n;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isVisited[30][30] = {false};
char arr[30][30] = {0};

int fun(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= n || isVisited[x][y] || arr[x][y] == '0') return 0;
    isVisited[x][y] = true;
    int ans = 1;
    for(int i = 0; i < 4; i++)
    {
        ans += fun(x + dx[i], y + dy[i]);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == '1' && !isVisited[i][j])
            {
                apartment.insert(fun(i, j));
            }
        }
    }
    printf("%d\n", apartment.size());
    for(auto a: apartment)
    {
        printf("%d\n", a);
    }

    return 0;
}
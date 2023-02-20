#include <iostream>
using namespace std;

char arr[10000][510];
bool isVisited[10000][501] = {false};
int ans = 0, r, c;
int dx[] = {-1, 0, 1};

bool check(int x, int y)
{
    if(x < 0 || x == r || arr[x][y] == 'x' || isVisited[x][y]) return false;
    if(y == c - 1)
    {
        ans++;
        return isVisited[x][y] = true;
    }

    isVisited[x][y] = true;
    for(int i = 0; i < 3; i++)
    {
        if(check(x + dx[i], y + 1))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        scanf("%s", arr[i]);
    }

    for(int i = 0; i < r; i++)
    {
        check(i, 0);
    }

    cout << ans << '\n';
    return 0;
}
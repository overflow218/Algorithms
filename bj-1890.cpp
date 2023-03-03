#include <iostream>
using namespace std;

int n;
int arr[100][100];
long long cache[100][100];

long long find(int x, int y)
{
    if(x == n - 1 && y == n - 1) return 1;
    long long &ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 0;
    if(x + arr[x][y] < n)
    {
        ret += find(x + arr[x][y], y);
    }
    if(y + arr[x][y] < n)
    {
        ret += find(x, y + arr[x][y]);
    }
    return ret;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            cache[i][j] = -1;
        }
    }

    cout << find(0, 0) << '\n';
    return 0;
}
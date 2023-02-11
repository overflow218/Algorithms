#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

int n;
int matrix[500][2];
int cache[500][500] = {0};

int find(int start, int end)
{
    if(start == end) return 0;
    int &ret = cache[start][end];
    if(ret != -1) return ret;

    ret = numeric_limits<int>::max();
    for(int k = start; k < end; k++)
    {
        int tmp = find(start, k) + find(k + 1, end);
        tmp += matrix[start][0] * matrix[k][1] * matrix[end][1];
        ret = min(tmp, ret);
    }
    return ret;
}

int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &matrix[i][0], &matrix[i][1]);
    }

    cout << find(0, n - 1) << '\n';
    return 0;
}
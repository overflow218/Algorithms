#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000;
vector<vector<int>> mul(vector<vector<int>> m1, vector<vector<int>> m2)
{
    vector<vector<int>> newMatrix;
    int n = m1.size();
    for(int i = 0; i < n; i++)
    {
        vector<int> vec;
        for(int j = 0; j < n; j++)
        {
            int tmp = 0;
            for(int k = 0; k < n; k++)
            {
                tmp = (tmp + ((m1[i][k] * m2[k][j]) % mod)) % mod;
            }
            vec.push_back(tmp);
        }
        newMatrix.push_back(vec);
    }
    return newMatrix;
}

vector<vector<int>> square(vector<vector<int>> matrix, long long n)
{
    if(n == 1ll) return matrix;
    vector<vector<int>> half = square(matrix, n / 2ll);
    if(n % 2ll == 1ll)
    {
        return mul(mul(half, half), matrix);
    }
    return mul(half, half);
}

int main()
{
    long long n, b;
    scanf("%lld %lld", &n, &b);
    vector<vector<int>> matrix;

    for(int i = 0; i < n; i++)
    {
        vector<int> vec;
        int tmp;
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &tmp);
            vec.push_back(tmp);
        }
        matrix.push_back(vec);
    }
    
    vector<vector<int>> ans = square(matrix, b);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", ans[i][j] % mod);
        }
        printf("\n");
    }
    return 0;
}
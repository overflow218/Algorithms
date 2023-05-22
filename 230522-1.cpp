#include <vector>
#include <cstring>
#include <limits>
using namespace std;

long long cache[200][200];

long long find(int l, int r, vector<vector<int>>& matrix_sizes)
{
    if(l == r) return 0;
    if(l + 1 == r) return matrix_sizes[l][0] * matrix_sizes[l][1] * matrix_sizes[r][1];
    long long &ret = cache[l][r];
    if(ret != -1) return ret;
    ret = numeric_limits<long long> :: max();
    for(int k = l; k < r; k++)
    {
        long long tmp = matrix_sizes[l][0] * matrix_sizes[k][1] * matrix_sizes[r][1];
        ret = min(ret, find(l, k, matrix_sizes) + find(k + 1, r, matrix_sizes) + tmp);
    }
    return ret;
}
int solution(vector<vector<int>> matrix_sizes) {
    memset(cache, -1, sizeof(cache));
    return find(0, matrix_sizes.size() - 1, matrix_sizes);
}
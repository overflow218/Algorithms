#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int idx;
bool cmp(vector<int> &a, vector<int> &b)
{
    if(a[idx] != b[idx]) return a[idx] < b[idx];
    return a[0] > b[0];
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    idx = col - 1;
    sort(data.begin(), data.end(), cmp);
    int answer = 0;
    for(int i = row_begin - 1; i < row_end; i++)
    {
        int s_i = 0;
        for(int j = 0; j < data[i].size(); j++)
        {
            s_i += data[i][j] % (i + 1);
        }
        answer ^= s_i;
    }
    return answer;
}
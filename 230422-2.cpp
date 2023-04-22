#include <string>
#include <vector>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    int lx = x, ly = y, rx = x, ry = y;
    int limit = queries.size();
    for(int i = limit - 1; i >= 0; i--)
    {
        int op = queries[i][0], d = queries[i][1];
        // <-
        if(op == 0)
        {
            if(ly == m - 1) return 0;
            ry = min(m - 1, ry + d);
            if(ly != 0) ly = min(m - 1, ly + d);
        }
        // -> 
        if(op == 1)
        {
            if(ry == 0) return 0;
            ly = max(0, ly - d);
            if(ry != m - 1) ry = max(0, ry - d);
        }
        // 로우 감소
        if(op == 2)
        {
            if(lx == n - 1) return 0;
            rx = min(n - 1, rx + d);
            if(lx != 0) lx = min(n - 1, lx + d);
        }
        // 로우 증가
        if(op == 3)
        {
            if(rx == 0) return 0;
            lx = max(0, lx - d);
            if(rx != n - 1) rx = max(0, rx - d);
        }
    }

    return (long long)(rx - lx + 1) * (long long)(ry - ly + 1);
}
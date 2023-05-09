#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> cores) {
    if(n <= cores.size()) return n;
    int start = 1, end = cores[0] * n, check = cores[0] * n;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 0;
        
        for(int i = 0; i < cores.size(); i++)
        {
            cnt += (mid / cores[i]) + 1;
        }
        if(cnt < n)
        {
            start = mid + 1;
        }
        if(cnt >= n)
        {
            check = min(check, mid);
            end = mid - 1;
        }
    }
    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < cores.size(); i++)
    {
        if(check % cores[i] == 0) ans.push_back(i);
        cnt += (check / cores[i]) + 1;
    }
    
    int idx = cnt - n;
    return ans[ans.size() - 1 - idx] + 1;
}
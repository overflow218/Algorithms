/*
가능한 모든 조합을 만든다고 생각하면 됨. 
8개 밖에 없으니까 8! = 4만개임. 각 경우마다 이제 개수를 k개의 뭉탱이로 분할해줘야함. 
8개일때 k개로 나눈다고 하면은
*/
#include <algorithm>
class Solution {
public:
    int ans = 987654321;
    vector<int> ho;
    void check(int idx, int k, vector<int> &perm, vector<int> &cookies)
    {
        if(ho.size() == k && idx == cookies.size())
        {
            int tmp = 0;
            for(const int &n: ho)
            {
                tmp = max(tmp, n);
            }
            ans = min(ans, tmp);
            return;
        }
        if(ho.size() == k || idx == cookies.size()) return;
        int cnt = 0;
        for(int i = 0; i + idx < cookies.size(); i++)
        {
            int tIdx = perm[idx + i];
            cnt += cookies[tIdx];
            ho.push_back(cnt);
            check(idx + i + 1, k, perm, cookies);
            ho.pop_back();
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> vec;
        for(int i = 0; i < n; i++)
        {
            vec.push_back(i);
        }
        int cnt = 0;
        do{
            check(0, k, vec, cookies);
            cnt++;
        } while(next_permutation(vec.begin(), vec.end()));
        return ans;
    }
};
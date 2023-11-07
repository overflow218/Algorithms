#include <algorithm>
using namespace std;
// leetcode 1921번
class Solution {
public:
    vector<int> check;
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 0;
        for(int i = 0; i < dist.size(); i++)
        {
            check.push_back(dist[i] % speed[i] == 0 ? dist[i] / speed[i] : dist[i] / speed[i] + 1);
        }
        sort(check.begin(), check.end());
        
        for(int i = 0; i < dist.size(); i++)
        {
            if(i >= check[i]) return i;
        }
        return dist.size();
    }
};

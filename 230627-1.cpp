#include <queue>
class Solution {
public:
    priority_queue<pair<int, int>> pq;
    vector<int> index = vector<int>(100000, 0);
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            pq.push(make_pair(-(nums1[i] + nums2[0]), i));
        }
        
        int cnt = 0;
        while(cnt < k && !pq.empty())
        {
            pair<int, int> tmp = pq.top();
            int idx = tmp.second;
            pq.pop();
            ans.push_back({nums1[idx], nums2[index[idx]]});
            cnt++;
            index[idx]++;
            if(index[idx] < m) pq.push(make_pair(-(nums1[idx] + nums2[index[idx]]), idx));
        }
        
        return ans;
    }
};
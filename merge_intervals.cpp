#include <algorithm>
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;

        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 0; i < intervals.size(); i++)
        {
            int newStart = intervals[i][0], newEnd = intervals[i][1];
            if(e < newStart)
            {
                ans.push_back({s, e});
                s = newStart;
                e = newEnd;
            } else 
            {
                e = max(e, newEnd);
            }
        }
        ans.push_back({s, e});

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int mergedStart = newInterval[0], mergedEnd = newInterval[1];
        // 1. 그냥 넣어도 되는경우. 2.합쳐야하는 경우

        bool isDone = false;
        int idx = 0, limit = intervals.size();
        while(idx < limit)
        {
            int curStart = intervals[idx][0], curEnd = intervals[idx][1];
            if(mergedEnd < curStart)
            {
                if(!isDone)
                {
                    ans.push_back({mergedStart, mergedEnd});
                    isDone = true;
                }
                ans.push_back(intervals[idx]);
            } else if(curEnd < mergedStart)
            {
                ans.push_back(intervals[idx]);
            } else if (mergedEnd >= curStart || mergedStart <= curEnd)
            {
                mergedEnd = max(mergedEnd, curEnd);
                mergedStart = min(curStart, mergedStart);
            } 
            idx++;
        }

        if(!isDone)
        {
            ans.push_back({mergedStart, mergedEnd});
        }
        return ans;
    }
};
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []
        isDone = False
        newStart, newEnd = newInterval[0], newInterval[1]
        for s, e in intervals:
            if(isDone):
                ans.append([s, e])
                continue
            if(newEnd < s):
                ans.append([newStart, newEnd])
                ans.append([s, e])
                isDone = True
            if(e < newStart):
                ans.append([s, e])
            else:
                newStart = min(s, newStart)
                newEnd = max(newEnd, e)
        if(not isDone):
            ans.append([newStart, newEnd])
        return ans
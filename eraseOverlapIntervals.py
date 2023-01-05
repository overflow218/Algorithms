class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        cnt = 0

        for i in range(1, len(intervals)):
            pStart, pEnd = intervals[i - 1]
            start, end = intervals[i]
            if(start < pEnd):
                cnt += 1
                if(pEnd < end):
                    intervals[i] = intervals[i - 1]
        return cnt
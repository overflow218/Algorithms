import heapq
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        heapq.heapify(intervals)
        q = []
        heapq.heapify(q)
        ans = 0
        while(intervals):
            start, end = heapq.heappop(intervals)
            heapq.heappush(q, end)
            while(q[0] <= start):
                heapq.heappop(q)
            ans = max(ans, len(q))
        return ans
        
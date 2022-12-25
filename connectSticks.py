import heapq
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapq.heapify(sticks)
        ans = 0
        while(len(sticks) > 1):
            a = heapq.heappop(sticks)
            b = heapq.heappop(sticks)
            ans += a + b
            heapq.heappush(sticks, a + b)
        return ans
        
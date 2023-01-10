import heapq
from math import ceil
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        heap = []
        for i in nums:
            heapq.heappush(heap, -i)
        ans = 0
        for _ in range(k):
            tmp = -heapq.heappop(heap)
            ans += tmp
            new_val = ceil(tmp / 3)
            heapq.heappush(heap, -new_val)
            
        return ans
        
        
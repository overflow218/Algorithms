import heapq
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        for i in range(len(piles)):
            piles[i] = -piles[i]
        heapq.heapify(piles)

        for _ in range(k):
            top = -heapq.heappop(piles)
            newNumber = top - (top) // 2
            heapq.heappush(piles, -newNumber)
        return -sum(piles)
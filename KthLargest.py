import heapq
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.q = nums
        self.k = k
        heapq.heapify(self.q)
        while(len(self.q) > k):
            heapq.heappop(self.q)

    def add(self, val: int) -> int:
        if(len(self.q) < self.k):
            heapq.heappush(self.q, val)
        elif(val > self.q[0]):
            heapq.heappop(self.q)
            heapq.heappush(self.q, val)
        return self.q[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
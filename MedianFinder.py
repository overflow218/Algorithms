import heapq
class MedianFinder:

    def __init__(self):
        self.max_heap = []
        heapq.heapify(self.max_heap)
        self.min_heap = []
        heapq.heapify(self.min_heap)

    def addNum(self, num: int) -> None:
        # 1. push to adequate heap
        if(not self.max_heap or not self.min_heap):
            heapq.heappush(self.max_heap, -num)
        elif(self.min_heap[0] > num):
            heapq.heappush(self.min_heap, num)
        else:
            heapq.heappush(self.max_heap, -num)
            
        # 2. balancing two heaps
        while(self.max_heap and len(self.max_heap) + 2 >= len(self.min_heap)):
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        while(self.min_heap and len(self.max_heap) < len(self.min_heap)):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
        
    def findMedian(self) -> float:
        if(len(self.min_heap) == len(self.max_heap)):
            return (self.min_heap[0] - self.max_heap[0]) / 2
        else:
            return -self.max_heap[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
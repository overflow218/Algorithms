import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        cnt = 0
        idx = [0 for i in range(n)]
        heap = []
        current = 0
        heapq.heapify(heap)
        for i in range(n):
            heapq.heappush(heap, (matrix[i][0], i))
        while(cnt < k):
            value, row = heapq.heappop(heap)
            if(cnt == k-1):
                return value
            idx[row] += 1
            if(idx[row] < n):
                heapq.heappush(heap, (matrix[row][idx[row]], row))
            cnt += 1
        return 0
        
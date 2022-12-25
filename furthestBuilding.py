import heapq
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        heap = []
        oBricks = bricks
        heapq.heapify(heap)
        idx = 0
        while(idx < len(heights) - 1):
            # go to next building
            if(heights[idx] >= heights[idx + 1]):
                idx += 1
            # use brick or ladder
            else:
                needed = heights[idx + 1] - heights[idx]
                if(bricks >= needed):
                    bricks -= needed
                    heapq.heappush(heap, -needed)
                    idx += 1
                # replace already used bricks with a ladder
                elif(ladders > 0):
                    if(heap and bricks - heap[0] >= needed and -heap[0] - needed > 0):
                        bricks += -heapq.heappop(heap)
                    else:
                        idx += 1
                    ladders -= 1
                else:
                    break
        return idx
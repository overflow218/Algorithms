from collections import deque
class Solution:
    def numSquares(self, n: int) -> int:
        limit = int(n ** 0.5)
        q = deque([n])
        stage = 0
        visited = set([n])
        while(q):
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                if(cur == 0):
                    return stage
                idx = 1
                while(cur - idx ** 2 >= 0):
                    tmp = cur - idx ** 2
                    if (tmp not in visited):
                        visited.add(tmp)
                        q.append(tmp)
                    idx += 1        
            stage += 1
        return 0
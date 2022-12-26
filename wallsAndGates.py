from collections import deque
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        INF = 2147483647
        q = deque([])
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
        m, n = len(rooms), len(rooms[0])
        visited = set()
        for i in range(m):
            for j in range(n):
                if(rooms[i][j] == 0):
                    q.append((i, j))
                    visited.add((i, j))
        
        distance = 0
        while(q):
            size = len(q)
            for j in range(size):
                x, y = q.popleft()
                if(rooms[x][y] == -1):
                    continue
                rooms[x][y] = distance
                for i in range(4):
                    nx, ny = x + dx[i], y + dy[i]
                    if(nx < 0 or nx >= m or ny < 0 or ny >= n):
                        continue
                    if(not (nx, ny) in visited):
                        visited.add((nx, ny))
                        q.append((nx, ny))
            distance += 1
        
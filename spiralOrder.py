class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        x, y = 0, 0
        m, n = len(matrix), len(matrix[0])
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        t = 0
        while(len(ans) < m * n):
            ans.append(matrix[x][y])
            matrix[x][y] = 0
            nx, ny = x + dx[t], y + dy[t]
            if(nx < 0 or nx >= m or ny < 0 or ny >= n or matrix[nx][ny] == 0):
                t = (t + 1) % 4
                nx, ny = x + dx[t], y + dy[t]
            x, y = nx, ny
        return ans
            
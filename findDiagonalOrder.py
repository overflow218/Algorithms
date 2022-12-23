class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        rightUpper = True
        leftLower = False
        x, y = 0, 0
        ans = []
        m, n = len(mat), len(mat[0])
        while(len(ans) < m * n):
            ans.append(mat[x][y])
            if(rightUpper):
                if(x == 0):
                    rightUpper = False
                    leftLower = True
                    if(y == n - 1):
                        x, y = x + 1, y
                    else:
                        x, y = x , y + 1
                else:
                    if(y == n - 1):
                        rightUpper = False
                        leftLower = True
                        x, y = x + 1, y
                    else:
                        x, y = x - 1, y + 1
            else:
                if(y == 0):
                    rightUpper = True
                    leftLower = False
                    if(x == m - 1):
                        x, y = x, y + 1
                    else:
                        x, y = x + 1, y
                else:
                    if(x == m - 1):
                        rightUpper = True
                        leftLower = False
                        x, y = x, y + 1
                    else:
                        x, y = x + 1, y - 1
        return ans
                        
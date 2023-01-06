from bisect import bisect_right
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            if(row[-1] < target):
                continue
            idx = bisect_right(row, target) - 1
            if(row[idx] == target):
                return True
        return False
from bisect import bisect_right, bisect_left
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = [r[0] for r in matrix]
        row_idx = bisect_right(row, target) - 1
        idx = bisect_right(matrix[row_idx], target) - 1
        return matrix[row_idx][idx] == target
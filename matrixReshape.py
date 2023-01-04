class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        # impossible case
        if(m * n != r * c):
            return mat
        serial = []
        for row in mat:
            serial += row
        ans = []
        for row in range(r):
            tmp = []
            for col in range(c):
                tmp.append(serial[row * c + col])
            ans.append(tmp)
        return ans
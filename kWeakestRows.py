class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        power = {}
        for idx, value in enumerate(mat):
            power[idx] = sum(value)
        return sorted([i for i in range(len(mat))], key = lambda x: (power[x], x))[:k]
            
        
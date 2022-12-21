class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        big = -1
        for i in range(len(arr) - 1, -1, -1):
            cp = big
            big = max(big, arr[i])
            arr[i] = cp
        return arr
        
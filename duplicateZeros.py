class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        limit = len(arr)
        idx = 0
        while(idx < limit):
            if(arr[idx] == 0):
                arr.insert(idx, 0)
                arr.pop()
                idx += 2
            else:
                idx += 1
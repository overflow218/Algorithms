class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        s = set(arr)
        zero = 0
        for i in arr:
            if(i == 0):
                zero += 1
            else:
                if(i * 2 in s):
                    return True
                
        return zero > 1
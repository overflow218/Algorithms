class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        isIncreasing = True
        isDecreasing = False
        if(arr[0] == max(arr)):
            return False
        
        for i in range(1, len(arr)):
            if(arr[i] == arr[i - 1]):
                return False
            if(arr[i] < arr[i - 1]):
                if(isIncreasing):
                    isDecreasing = True
                    isIncreasing = False
            else:
                if(isDecreasing):
                    return False
        return True and not isIncreasing
                
        
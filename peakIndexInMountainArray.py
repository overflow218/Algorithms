class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        s, e = 0, len(arr) - 1
        while(s <= e):
            mid = (s + e) // 2
            if(arr[mid -1] < arr[mid] and arr[mid] > arr[mid + 1]):
                return mid
            if(arr[mid -1] < arr[mid]):
                s = mid
            else:
                e = mid
        return 0
        
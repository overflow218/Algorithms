# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#	 # Compares the sum of arr[l..r] with the sum of arr[x..y]
#	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
#	 # return 0 if sum(arr[l..r]) == sum(arr[x..y])
#	 # return -1 if sum(arr[l..r]) < sum(arr[x..y])
#    def compareSub(self, l: int, r: int, x: int, y: int) -> int:
#
#	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def getIndex(self, reader: 'ArrayReader') -> int:
        start, end = 0, reader.length() - 1
        for _ in range(20):
            if(start == end):
                return start
            mid = (start + end) // 2
            res = reader.compareSub(start, mid, mid + 1, end) if (end - start) % 2 == 1 else reader.compareSub(start, mid, mid, end)
            if(res == 1):
                end = mid
            elif(res == -1):
                start = mid + 1 if (end - start) % 2 == 1 else mid
            else:
                return mid
        return -1
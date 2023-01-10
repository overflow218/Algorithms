# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        s, e = 1, n
        while(s <= e):
            mid = (s + e) // 2
            ans = guess(mid)
            if(ans < 0):
                e = mid - 1
            elif(ans > 0):
                s = mid + 1
            else:
                return mid
        return 0
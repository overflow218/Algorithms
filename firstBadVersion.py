# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        ans = n
        s, e = 1, n
        while(s <= e):
            mid = (s + e) // 2
            if(isBadVersion(mid)):
                ans = min(ans, mid)
                e = mid - 1
            else:
                s = mid + 1
        return ans
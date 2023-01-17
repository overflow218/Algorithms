from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = list(Counter(s).values())
        ans, odd = 0, 0
        for n in cnt:
            if(n % 2 == 1):
                ans += n - 1
                odd += 1
            else:
                ans += n
        if(odd > 0):
            ans += 1
        return ans
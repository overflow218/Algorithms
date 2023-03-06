from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        counter = Counter(s)
        ans = 0
        big = 0
        for i in counter:
            if(counter[i] % 2 == 0):
                ans += counter[i]
            else:
                ans += counter[i] - 1
                big = 1
        return ans + big
        
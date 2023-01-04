class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        small = prices[0]
        for n in prices:
            if(small < n):
                ans = max(ans, n - small)
            if(small > n):
                small = n
        return ans
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curPrice = 20000
        ans = 0
        for price in prices:
            if(curPrice > price):
                curPrice = price
            else:
                ans = max(ans, price - curPrice)
        return ans
        
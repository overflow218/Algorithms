class Solution:
    def countOdds(self, low: int, high: int) -> int:
        ans = high // 2 - low // 2
        if(high % 2 == 1):
            ans += 1
        return ans
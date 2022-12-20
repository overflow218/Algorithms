class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans = 0
        for account in accounts:
            tmpSum = sum(account)
            ans = max(ans, tmpSum)
        return ans
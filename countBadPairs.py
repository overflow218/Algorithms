class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        check = {}
        for idx, val in enumerate(nums):
            tmp = val - idx
            if(tmp not in check):
                check[tmp] = 0
            check[tmp] += 1
        ans = len(nums) * (len(nums) - 1) // 2
        for num in check.values():
            if(num >= 2):
                ans -= num * (num - 1) // 2
        return ans
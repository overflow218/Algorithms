class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        check = {0: 1}
        pSum, ans = 0, 0
        for num in nums:
            pSum += num
            ans += check.get(pSum - k, 0)
            if(pSum not in check):
                check[pSum] = 0
            check[pSum] += 1
        return ans
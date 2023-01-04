class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pSum = [0]
        ans = -987654321
        for num in nums:
            if(num > pSum[-1] + num):
                pSum.append(num)
            else:
                pSum.append(num + pSum[-1])
            ans = max(ans, pSum[-1])
        return ans
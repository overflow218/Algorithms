class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        tmpSum = nums[0]
        ans = nums[0]
        for num in nums[1:]:
            ans = max(ans, tmpSum)
            if(tmpSum >= 0):
                tmpSum += num
            else:
                ans = max(ans, tmpSum)
                tmpSum = num
        ans = max(ans, tmpSum)
        return ans
        
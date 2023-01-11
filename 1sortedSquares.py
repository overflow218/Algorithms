from bisect import bisect_left
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        neg = bisect_left(nums, 0) - 1
        pos = neg + 1
        ans = []

        while(neg >=0 or pos < len(nums)):
            if(neg < 0 or (pos < len(nums) and abs(nums[neg]) > nums[pos])):
                ans.append(nums[pos] * nums[pos])
                pos += 1
            else:
                ans.append(nums[neg] * nums[neg])
                neg -= 1
        return ans
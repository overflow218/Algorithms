class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        if(k == 0):
            return nums[0]
        if(len(nums) == 1):
            return nums[0] if k % 2 == 0 else -1
        elif(k == 1):
            return nums[1] if (len(nums) > 1) else -1
        else:
            if(k > len(nums)):
                return max(nums)
            elif(k == len(nums)):
                return max(nums[:-1])
            return max(nums[k], max(nums[:k - 1]))
            
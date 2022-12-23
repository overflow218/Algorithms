class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        idx = -1
        pSum = 0;
        for i in range(len(nums)):
            if(pSum * 2 == total - nums[i]):
                idx = i
                break
            pSum += nums[i]
        return idx
        
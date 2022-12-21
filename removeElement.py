class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        for i in range(len(nums)):
            if(nums[i] == val):
                nums[i] = -1
        idx = 0
        for i in range(len(nums)):
            if(nums[i] != -1):
                nums[idx] = nums[i]
                idx += 1
        return idx
        
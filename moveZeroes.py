class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        front = 0
        for i in range(len(nums)):
            if(nums[i] != 0):
                nums[front] = nums[i]
                front += 1
        for i in range(front, len(nums)):
            nums[i] = 0
        
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 0 for up, 1 for down
        idx = 0
        while(idx < len(nums) - 1):
            if(idx % 2 == 0): #up
                if(nums[idx] > nums[idx + 1]):
                    nums[idx], nums[idx + 1] = nums[idx + 1], nums[idx]
            else: # down
                if(nums[idx] < nums[idx + 1]):
                    nums[idx], nums[idx + 1] = nums[idx + 1], nums[idx]
            idx += 1
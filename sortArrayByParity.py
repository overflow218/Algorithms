class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        odd = 0
        idx = 0
        while(idx < len(nums)):
            if(nums[idx] % 2 == 0):
                nums[odd], nums[idx] = nums[idx], nums[odd]
                odd += 1
            idx += 1
        return nums
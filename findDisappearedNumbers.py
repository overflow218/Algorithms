class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for idx in range(1, len(nums) + 1):
            while(True):
                val = nums[idx - 1]
                if(idx == val):
                    break
                else:
                    if(val == nums[val - 1]):
                        break
                    else:
                        nums[idx - 1], nums[val - 1] = nums[val - 1], nums[idx - 1]
        return [i + 1 for i in range(len(nums)) if nums[i] != i + 1]
        
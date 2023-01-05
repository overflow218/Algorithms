class Solution:
    def minMoves(self, nums: List[int]) -> int:
        nums.sort()
        return sum([n - nums[0] for n in nums[1:]])
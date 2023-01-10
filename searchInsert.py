class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        s, e = 0, len(nums) - 1
        ans = len(nums)
        while(s <= e):
            mid = (s + e) // 2
            if(nums[mid] >= target):
                ans = min(ans, mid)
                e = mid - 1
            else:
                s = mid + 1
        return ans
            
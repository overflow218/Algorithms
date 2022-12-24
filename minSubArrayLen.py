class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = 1000000
        s, e = 0, 0
        tmp_sum = 0
        while(s < len(nums) or e < len(nums)):
            if(tmp_sum >= target or e == len(nums)):
                if(tmp_sum >= target):
                    ans = min(ans, e - s)
                tmp_sum -= nums[s]
                s += 1
            else:
                tmp_sum += nums[e]
                e += 1
        return 0 if ans == 1000000 else ans
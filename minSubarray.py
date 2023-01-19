class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        if(total % p == 0):
            return 0
        ans = len(nums)
        needed = total % p
        pSum = 0
        last_idx = {0: -1}
        for i in range(len(nums)):
            if(nums[i] % p == needed):
                return 1
            pSum += nums[i]
            cur_idx = pSum % p
            last_idx[cur_idx] = i
            if(cur_idx >= needed and cur_idx - needed in last_idx):
                ans = min(ans, i - last_idx[cur_idx - needed])
            elif(cur_idx < needed and cur_idx + p - needed in last_idx):
                ans = min(ans, i - last_idx[cur_idx + p - needed])
        return ans if ans < len(nums) else -1
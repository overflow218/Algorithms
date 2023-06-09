class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        for num in nums:
            if(num - 1 in s): continue
            tmp_cnt = 1
            tmp = num + 1
            while(tmp in s):
                tmp_cnt += 1
                tmp += 1
            ans = max(ans, tmp_cnt)
        return ans
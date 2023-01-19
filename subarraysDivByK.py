class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        partial_mod = {i: 0 for i in range(k)}
        pSum = 0
        for num in nums:
            pSum = pSum + num
            partial_mod[pSum % k] += 1
        ans = 0
        for v in partial_mod.values():
            if(v >= 2):
                ans += v*(v - 1)//2
        return ans + partial_mod[0]
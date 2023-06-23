class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        check = {}
        for num in nums:
            mod = num % space
            if(mod not in check):
                check[mod] = 0
            check[mod] += 1
        val = max(check.values())
        return min([num for num in nums if check[num % space] == val])
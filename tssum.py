from collections import Counter


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        counter = Counter(nums)

        for i in counter:
            if(i > 0): break
            for j in counter:
                if(i <= j):
                    target = -(i + j)
                    if(j <= target and target in counter):
                        tmpCounter = Counter([i, j, target])
                        isPossible = True
                        for x in tmpCounter:
                            if(tmpCounter[x] > counter[x]):
                                isPossible = False
                        if(isPossible):
                            ans.append((i, j, target))
        return list(set(ans))
        
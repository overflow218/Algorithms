class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        ans = 0
        for v1, v2 in zip(heights, sorted(heights)):
            if(v1 != v2):
                ans += 1
        return ans

        
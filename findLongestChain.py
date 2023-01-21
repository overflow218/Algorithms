class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        global ans
        ans = 0
        pairs.sort(key = lambda x: (x[1], x[0]))
        last = pairs[0][0] - 1
        for s, e in pairs:
            if(last < s):
                ans += 1
                last = e
        return ans
            
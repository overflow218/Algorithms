class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        dic = {}
        for n in nums:
            dic[n] = dic.get(n, 0) + 1
        ans = 0 
        for key in dic:
            if(k == 0):
                ans += 1 if dic[key] > 1 else 0
            elif(key + k in dic):
                ans += 1
        return ans
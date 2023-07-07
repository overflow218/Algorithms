class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        dic = {}
        start, end, ans = 0, 0, 0
        n = len(s)
        while(end < n):
            if(s[end] not in dic):
                dic[s[end]] = 0
            dic[s[end]] += 1
            end += 1
            while(len(dic) > k):
                dic[s[start]] -= 1
                if(dic[s[start]] == 0):
                    del dic[s[start]]
                start += 1
            ans = max(ans, end - start)
        return ans
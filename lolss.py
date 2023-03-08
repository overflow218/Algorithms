class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lastIdx = {}
        ans, validIdx = 0, -1

        for i in range(len(s)):
            if(s[i] in lastIdx):
                if(lastIdx[s[i]] > validIdx):
                    validIdx = lastIdx[s[i]]
            lastIdx[s[i]] = i
            ans = max(ans, i - validIdx)
        return ans

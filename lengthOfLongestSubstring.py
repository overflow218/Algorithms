from collections import deque
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        check = {}
        q = deque([])
        for c in s:
            if(c not in check):
                check[c] = len(q)
                q.append(c)
            else:
                ans = max(ans, len(q))
                for i in range(check[c] + 1):
                    del check[q.popleft()]
                q.append(c)
                for i in range(len(q)):
                    check[q[i]] = i
        ans = max(ans, len(q))
        return ans
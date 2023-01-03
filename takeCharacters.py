from collections import Counter
class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        counter = Counter(s)
        if(any(counter[x] < k for x in 'abc')):
            return -1
        limit = { c: counter[c] - k for c in 'abc'}
        length, l = 0, 0
        count = {c: 0 for c in 'abc'}
        for idx, value in enumerate(s):
            count[value] += 1
            while(limit[value] < count[value]):
                count[s[l]] -= 1
                l += 1
            length = max(length, idx - l + 1)
        return len(s) - length
        
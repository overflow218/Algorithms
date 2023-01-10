from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counter_s = Counter(s)
        counter_t = Counter(t)
        for c in 'abcdefghijklmnopqrstuvwxyz':
            if(counter_s[c] != counter_t[c]):
                return False
        return True
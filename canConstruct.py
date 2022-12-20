from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        note = Counter(ransomNote)
        mag = Counter(magazine)
        for c in note:
            if (c not in mag) or mag[c] < note[c]:
                return False
        return True
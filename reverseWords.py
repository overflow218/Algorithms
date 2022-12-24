class Solution:
    def reverseWords(self, s: str) -> str:
        parsed = s.strip().split()
        return ' '.join(parsed[::-1])
        
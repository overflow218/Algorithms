class Solution:
    def reverseWords2(self, s: str) -> str:
        return ' '.join([i[::-1] for i in s.split(' ')])
        
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        front, end = 0, len(s) - 1
        while(front < end):
            s[front], s[end] = s[end], s[front]
            front += 1
            end -=1
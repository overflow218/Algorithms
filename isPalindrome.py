class Solution:
    def isPalindrome(self, x: int) -> bool:
        check = str(x)
        return check == check[::-1]
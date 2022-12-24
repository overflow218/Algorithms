class Solution:
    def convertToBase7(self, num: int) -> str:
        if(num == 0):
            return '0'
        ans = ""
        neg = '-' if num < 0 else ''
        num = abs(num)
        while(num):
            ans = str(num % 7) + ans
            num //= 7
        return neg + ans
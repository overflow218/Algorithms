class Solution:
    def addDigits(self, num: int) -> int:
        while(True):
            num = sum([int(i) for i in str(num)])
            if(num < 10):
                return num
        return 0
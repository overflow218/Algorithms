class Solution:
    def confusingNumber(self, n: int) -> bool:
        invalid = [2, 3, 4, 5, 7]
        valid = {0: 0, 1: 1, 6:9, 8: 8, 9: 6}
        new_num = 0
        copy_n = n
        while(n):
            tmp = n % 10
            n //= 10
            if(tmp in invalid):
                return False
            new_num = new_num * 10 + valid[tmp]
        return new_num != copy_n
class Solution:
    def countDigits(self, num: int) -> int:
        tmp_num = num
        cnt = 0
        while(tmp_num):
            ho = tmp_num % 10
            cnt += 0 if num % ho else 1
            tmp_num //= 10
        return cnt
            
        
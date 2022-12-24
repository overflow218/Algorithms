class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while(n):
            cnt += n % 2
            n //= 2
        return cnt
        
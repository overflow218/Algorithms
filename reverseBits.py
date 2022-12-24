class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            cur = n % 2
            if(cur):
                ans += 2 ** (31 - i)
            n = n >> 1
        return ans
        
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        lis = []
        while(n):
            lis.append(n % 10)
            n //= 10
        mul = 1
        for n in lis:
            mul *= n
        return mul - sum(lis)
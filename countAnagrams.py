from collections import Counter
class Solution:
    def __init__(self):
        self.mod = 10 ** 9  + 7
    def square(self, x, n): # x ** n 을 구함
        if(n == 0):
            return 1
        half = self.square(x, n // 2)
        if(n % 2 == 1):
            return self.multiply(self.multiply(half, half), x)
        else:
            return self.multiply(half, half)
        
    def multiply(self, a, b):
        return ((a % self.mod) * (b % self.mod)) % self.mod
    
    def moduloMulInverse(self, x):
        return self.square(x, self.mod - 2)
    
    def countAnagrams(self, s: str) -> int:
        splited = s.split(' ')
        facto = {0: 1}
        max_len = max([len(word) for word in splited])
        tmp = 1
        for i in range(1, max_len + 1):
            tmp = (tmp * i) % self.mod
            facto[i] = tmp
        ans = 1
        for word in splited:
            count = list(Counter(word).values())
            upper = facto[len(word)]
            lower = 1
            for n in count:
                lower = self.multiply(lower, facto[n])
            tmp = self.multiply(upper, self.moduloMulInverse(lower))
            ans = self.multiply(ans, tmp)
        return ans
            
            
        
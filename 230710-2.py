class Solution:
    def isFascinating(self, n: int) -> bool:
        check = str(n) + str(2 * n) + str(3 * n)
        ho = {}
        for c in check:
            if c not in ho:
                ho[c] = 0
            ho[c] += 1
        for key in check:
            if(key == '0'): return False
            if(ho[key] != 1): return False
        return True
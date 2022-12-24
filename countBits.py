class Solution:
    def countBits(self, n: int) -> List[int]:
        cache = {}
        ans = []
        for i in range(n + 1):
            if(i == 0 or i == 1):
                ans.append(1 & i)
                cache[i] = 1 & i
            else:
                common = i & (i - 1)
                left = i - common
                tmp = 1
                if(common != 0):
                    tmp = cache[common] + cache[left]
                ans.append(tmp)
                cache[i] = tmp
        return ans
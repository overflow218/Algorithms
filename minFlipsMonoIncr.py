from collections import Counter
class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        cnt = Counter(s)
        zero = cnt['0']
        one = cnt['1']
        start, end = 0, len(s) - 1

        ans = 100000
        cnt = 0
        while(start <= end):
            if(s[start] == '0'):
                zero -= 1
                start += 1
            else:
                tmp = one if one < zero else zero
                ans = min(ans, tmp + cnt)
                one -= 1
                start += 1
                cnt += 1
        return ans
#"01111010011111110100000101110100011000000010011010"
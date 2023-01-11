class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic1 = {}
        dic2 = {}

        cnt1 = 0
        cnt2 = 0
        for i in range(len(s)):
            c1 = s[i]
            c2 = t[i]
            if(c1 not in dic1):
                dic1[c1] = cnt1
                cnt1 += 1
            if(c2 not in dic2):
                dic2[c2] = cnt2
                cnt2 += 1
            if(dic1[c1] != dic2[c2]):
                return False
        return True
            
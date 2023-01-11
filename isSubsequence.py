class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        idx1, idx2 = 0, 0
        while(idx1 < len(s) and idx2 < len(t)):
            if(s[idx1] == t[idx2]):
                idx1 += 1
                idx2 += 1
            else:
                idx2 += 1
        return idx1 == len(s)
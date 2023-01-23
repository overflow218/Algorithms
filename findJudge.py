class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trusted = {i: 0 for i in range(1,n + 1)}
        trusting = {i: 0 for i in range(1,n + 1)}

        for a, b in trust:
            trusted[b] += 1
            trusting[a] += 1
        
        for i in trusted:
            if(trusted[i] == n - 1 and trusting[i] == 0):
                return i
        return -1
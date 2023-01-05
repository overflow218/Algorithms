class Solution:
    def captureForts(self, forts: List[int]) -> int:
        n = len(forts)
        idx, cnt, ans, start = 1, 0, 0, forts[0]
        while(idx < n):
            if(start != 0 and forts[idx] == 0):
                cnt += 1
            else:
                if(start * forts[idx] > 0):
                    cnt = 0
                else:
                    ans = max(ans, cnt)
                    cnt = 0
                    start = forts[idx]
            idx += 1
        return ans
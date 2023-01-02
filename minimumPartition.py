class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        idx, cnt = 0, 0
        tmp = ''
        while(idx < len(s)):
            if(tmp == '' or int(tmp + s[idx]) <= k):
                tmp += s[idx]
                idx += 1
            else:
                if(int(tmp) <= k):
                    cnt += 1
                    tmp = ''
                else:
                    return -1
        if(tmp and int(tmp) <= k):
            cnt += 1
        else:
            return -1
        return cnt
        
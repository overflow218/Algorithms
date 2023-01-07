from collections import deque
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        q = deque()
        ans = []
        cnt, idx = 0, 0
        while(idx < len(arr)):
            if(cnt < target):
                q.append((arr[idx], idx))
                cnt += arr[idx]
                idx += 1
            while(cnt > target):
                cnt -= q.popleft()[0]
            if(cnt == target):
                ans.append((len(q), q[0][1], q[-1][1]))
                cnt -= q.popleft()[0]
        cnt, idx = 987654321, 0
        if(not ans):
            return -1
        tmp = [ans[0][0]]
        for ho in ans:
            cost, start, end = ho
            while(ans[idx][2] < start):
                tmp.append(min(ans[idx][0], tmp[-1]))
                idx += 1
            if(idx > 0):
                cnt = min(cnt, tmp[-1] + cost)
        return -1 if cnt == 987654321 else cnt
import heapq
class Solution:
    def findCrossingTime(self, n: int, k: int, time: List[List[int]]) -> int:
        '''
        on bridge (leftToRight + rightToLeft , idx)
        on warehouse (time when done, idx)
        '''
        left = []
        right = []
        left_ware = []
        right_ware = []
        cnt = 0
        for idx, t in enumerate(time):
            heapq.heappush(left, (-t[0] - t[2], -idx))
        old_box = n
        while(n > 0):
            # right -> left 다리 건널친구들 다 건너게 하기 
            while(right_ware and right_ware[0][0] <= cnt):
                _, idx = heapq.heappop(right_ware)
                # print(f'{idx}번 오른쪽 창고에서 뺐음, 현재시간: {cnt}')
                heapq.heappush(right, (-time[idx][0] - time[idx][2], -idx))
            while(right):
                _, idx = heapq.heappop(right)
                idx = -idx
                n -= 1
                cnt += time[idx][2]
                # print(f'{idx}번 오른쪽 다리 건넘, 현재시간: {cnt}')
                if(n == 0):
                    return cnt
                heapq.heappush(left_ware, (cnt + time[idx][3], idx))
                while(right_ware and right_ware[0][0] <= cnt):
                    _, idx = heapq.heappop(right_ware)
                    heapq.heappush(right, (-time[idx][0] - time[idx][2], -idx))
            while(left_ware and left_ware[0][0] <= cnt):
                _, idx = heapq.heappop(left_ware)
                heapq.heappush(left, (-time[idx][0] - time[idx][2], -idx))
            if(left and old_box > 0):
                _, idx = heapq.heappop(left)
                idx = -idx
                cnt += time[idx][0]
                old_box -= 1
                # print(f'{idx}번 들어갔음, 현재시간: {cnt}')
                heapq.heappush(right_ware, (cnt + time[idx][1], idx))
            else:
                cnt += 1
        return 0
        
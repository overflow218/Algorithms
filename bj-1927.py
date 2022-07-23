import heapq
import sys
n = int(input())
h = []
for i in range(n):
    x = int(sys.stdin.readline())
    if(x == 0):
        tmp = 0 if len(h) == 0 else heapq.heappop(h)
        print(tmp)
    else:
        heapq.heappush(h, x)
from collections import deque
import sys
t = int(input())
for k in range(t):
    input = sys.stdin.readline().split()
    n, m = int(input[0]), int(input[1])
    lis = list(map(int, sys.stdin.readline().split()))
    lis = [lis[i] + 0.001 * i for i in range(n)]
    target = lis[m]
    deq = deque(lis)
    cnt = 0
    while(True):
        if(int(deq[0]) == int(max(deq))):
            cnt += 1
            if(deq.popleft() == target): break
        else:
            deq.append(deq.popleft())
    print(cnt)
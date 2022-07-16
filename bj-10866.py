from collections import deque
import sys
deq = deque()
n = int(input())
for i in range(n):
    cmd = sys.stdin.readline().split()
    try:
        if(cmd[0] == "push_front"):
            deq.appendleft(int(cmd[1]))
        if(cmd[0] == "push_back"):
            deq.append(int(cmd[1]))
        if(cmd[0] == "pop_front"):
            print(deq.popleft())
        if(cmd[0] == "pop_back"):
            print(deq.pop())
        if(cmd[0] == "front"):
            print(deq[0])
        if(cmd[0] == "back"):
            print(deq[-1])
        if(cmd[0] == "size"):
            print(len(deq))
        if(cmd[0] == "empty"):
            print(f"{1 if len(deq) == 0 else 0}")
    except:
        print(-1)
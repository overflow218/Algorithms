from collections import deque
import sys
def sol():
    n = int(input())
    deq = deque([0])
    cnt = 0
    lis = []
    ans = []
    for i in range(n):
        lis.append(int(sys.stdin.readline()))
    for i in lis:
        if(deq[-1] > i):
            print("NO")
            return
        if(deq[-1] < i):
            while(cnt < i):
                deq.append(cnt + 1)
                cnt += 1
                ans.append("+")
        if(deq[-1] == i):
            ans.append("-")
            deq.pop()
    print('\n'.join(ans))
sol()
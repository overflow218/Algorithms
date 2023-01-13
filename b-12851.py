import sys
from collections import deque
n, k = map(int, sys.stdin.readline().split())
is_visited = [False] * 100001
q = deque([(n, 1)])
stage = 0

is_done = False
while(q):
    limit = len(q)
    check = {}
    for _ in range(limit):
        cur, cnt = q.popleft()
        is_visited[cur] = True
        if(cur == k):
            print(stage)
            print(cnt)
            is_done = True
            break
        if(cur > k):
            if(cur - 1 not in check):
                check[cur - 1] = 0
            check[cur - 1] += cnt
        else:
            if(cur - 1 not in check):
                check[cur - 1] = 0
            check[cur - 1] += cnt

            if(cur + 1 not in check):
                check[cur + 1] = 0
            check[cur + 1] += cnt

            if(cur * 2 not in check):
                check[cur * 2] = 0
            check[cur * 2] += cnt

    if(is_done):
        break

    for key in check:
        if(key >= 0 and key <= 100000 and not is_visited[key]):
            q.append((key, check[key]))
    stage += 1
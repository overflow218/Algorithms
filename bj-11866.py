from collections import deque
lis = list(map(int, input().split()))
n, k = lis[0], lis[1]
q = deque([i + 1 for i in range(n)])
ans = []
while(len(q)):
    for i in range(k - 1):
        q.append(q.popleft())
    ans.append(str(q.popleft()))
print("<" + ", ".join(ans) + ">")
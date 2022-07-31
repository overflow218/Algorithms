from collections import deque
n = int(input())
m = int(input())
broken = list(map(int, input().split()))
working = [i for i in range(10) if i not in broken]
ans = 987654321
q = deque()
q.append((100, 0))
for i in working:
    q.append((i, 1))

while(len(q) > 0):
    current = q.popleft()
    print(current)
    ans = min(ans, abs(n - current[0]))
    if(current[0] >= n): continue
    else:
        for i in working:
            q.append((current[0] * 10 + i , current[1] + 1))
print(ans)
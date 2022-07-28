import sys
from collections import deque

n = int(input())
graph = [list(map(int, sys.stdin.readline().split())) for i in range(n)]
connected = [[0] * n for i in range(n)]
q = deque()
for idx1, l in enumerate(graph):
    for idx2, v in enumerate(l):
        if(v == 1):
            q.append((idx1, idx2))

while(len(q) > 0):
    s, e = q[0][0], q[0][1]
    q.popleft()
    if(connected[s][e] == 1): continue
    connected[s][e] = 1
    for i, v in enumerate(graph[e]):
        if(v):
            q.append((s, i))

for i in connected:
    print(' '.join([str(n) for n in i]))

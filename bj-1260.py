import sys
from collections import deque
a = list(map(int, sys.stdin.readline().split()))
n, m, v = a[0], a[1], a[2]
board = [[0] * (n + 1) for i in range((n + 1))]
isVisited = [False] * (n + 1)

def dfs(x):
    if(isVisited[x]): return
    isVisited[x] = True
    print(x, end = " ")
    for i in range(1, n + 1):
        if(board[x][i] == 1):
            dfs(i)

for i in range(m):
    b = list(map(int, sys.stdin.readline().split()))
    board[b[0]][b[1]] = 1
    board[b[1]][b[0]] = 1
dfs(v)
isVisited = [False] * 1001
print()
deq = deque([v])
while(len(deq) > 0):
    current = deq.popleft()
    if(isVisited[current] == False):
        isVisited[current] = True
        print(current, end = " ")
        for i in range(1, n + 1):
            if(board[current][i] == 1):
                deq.append(i)
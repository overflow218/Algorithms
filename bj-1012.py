import sys
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
m, n, k = 0, 0, 0
bot = []
def go(x, y):
    if(x < 0 or x == n or y < 0 or y == m):
        return
    if(bot[x][y] == 0): return
    bot[x][y] = 0
    for i in zip(dx, dy):
        go(x + i[0], y + i[1])

t = int(sys.stdin.readline())
for h in range(t):
    lis = list(map(int, sys.stdin.readline().split()))
    m, n, k = lis[0], lis[1], lis[2]
    bot = [[0] *  m for i in range(n)]
    for i in range(k):
        bug = list(map(int, sys.stdin.readline().split()))
        bot[bug[1]][bug[0]] = 1
    cnt = 0
    for x in range(n):
        for y in range(m):
            if(bot[x][y]):
                go(x, y)
                cnt += 1
    print(cnt)
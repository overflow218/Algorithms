import sys
sys.setrecursionlimit(10000)
a = input().split()
n, m = int(a[0]), int(a[1])
route = {}
radder = {}
snake = {}

def go(x):
    global route
    global radder
    global snake
    if(x == 100):return 0
    if(x > 100): return 987654321
    if(x in route): return route[x]
    if(x in radder): return go(radder[x])
    if(x in snake): return go(snake[x])
    ans = 987654321
    for i in range(1, 7):
        ans = min(ans, go(x + i) + 1)
    route[x] = ans
    return ans

for i in range(n):
    a = input().split()
    radder[int(a[0])] = int(a[1])
for i in range(m):
    a = input().split()
    snake[int(a[0])] = int(a[1])
print(go(1))
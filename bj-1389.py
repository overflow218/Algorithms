import sys
sys.setrecursionlimit(1000000)
a = sys.stdin.readline().split()
n, m = int(a[0]), int(a[1])
bacon = [[0] * (n + 1) for i in range(n + 1)]
for i in range(m):
    a = list(map(int, sys.stdin.readline().split()))
    bacon[a[0]][a[1]] = 1
    bacon[a[1]][a[0]] = 1

def fun(start, end):
    global bacon
    if(start == end): return 0
    if(bacon[start][end] != 0):
        return bacon[start][end]
    ans = 200
    for i in range(1, n + 1):
        if(bacon[start][i] == 1):
            ans = min(ans, fun(i, end) + 1)
    bacon[start][end] = ans
    return ans
person, steps = 0, 987654321
for i in range(1, n + 1):
    tmp = sum([fun(i, j) for j in range(1, n + 1)])
    if(tmp < steps):
        steps = tmp
        person = i
print(person)

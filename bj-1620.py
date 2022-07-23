import sys
a = list(map(int, sys.stdin.readline().split()))
n, m = a[0], a[1]
poke = {}
for i in range(1, n + 1):
    p = sys.stdin.readline().strip()
    poke[p] = str(i)
    poke[str(i)] = p
for i in range(m):
    p = sys.stdin.readline().strip()
    print(poke[p])
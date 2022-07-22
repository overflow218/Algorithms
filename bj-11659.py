import sys
a = list(map(int, sys.stdin.readline().split()))
n, m = a[0], a[1]
sum = list(map(int, sys.stdin.readline().split()))
pSum = [0, sum[0]]
for i in range(1, n):
    pSum.append(pSum[-1] + sum[i])
for i in range(m):
    a = list(map(int, sys.stdin.readline().split()))
    print(pSum[a[1]] - pSum[a[0] - 1])
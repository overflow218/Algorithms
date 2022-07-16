import sys
n = int(sys.stdin.readline())
lis = [0] * 10001
for i in range(n):
    lis[int(sys.stdin.readline())] += 1
for i in range(10001):
    for j in range(lis[i]):
        print(i)
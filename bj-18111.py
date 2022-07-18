import sys
cons = input().split()
n, b = int(cons[0]), int(cons[2])
lis = []
for i in range(n):
    lis.append(list(map(int, sys.stdin.readline().split())))
lis = [y for x in lis for y in x]
print(lis)
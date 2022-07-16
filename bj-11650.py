import sys
import functools
n = int(input())
lis = []
for i in range(n):
    lis.append(list(map(int, sys.stdin.readline().split())))
for i in sorted(lis, key = functools.cmp_to_key(lambda x, y: x[0] - y[0] if x[0] != y[0] else x[1] - y[1])):
    print(f"{i[0]} {i[1]}")
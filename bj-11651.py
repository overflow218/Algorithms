import sys
import functools
n = int(input())
lis = []
for i in range(n):
    lis.append(list(map(int, sys.stdin.readline().split())))
for i in sorted(lis, key = functools.cmp_to_key(lambda x, y: x[1] - y[1] if x[1] != y[1] else x[0] - y[0])):
    print(f"{i[0]} {i[1]}")
import sys
import functools
n = int(input())
lis = []
for i in range(n):
    lis.append(sys.stdin.readline().split())
for i in sorted(lis, key = functools.cmp_to_key(lambda x, y: int(x[0]) - int(y[0]))):
    print(' '.join(i))
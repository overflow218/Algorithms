from collections import Counter
import math
import sys
n = int(input())
lis = []
for i in range(n):
    lis.append(int(sys.stdin.readline()))
lis.sort()
c = Counter(lis).most_common()
try:
    common = c[0][0] if c[0][1] != c[1][1] else c[1][0]
except:
    common = c[0][0]
print(round(sum(lis) / n))
print(lis[n // 2])
print(common)
print(lis[-1] - lis[0])
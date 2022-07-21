import sys
s1 = set()
s2 = set()
input = sys.stdin.readline().split()
n, m = int(input[0]), int(input[1])
for i in range(n):
    s1.add(sys.stdin.readline())
for i in range(m):
    s2.add(sys.stdin.readline())
ans = s1 & s2
print(len(ans))
for i in sorted(list(ans)):
    print(i, end = "")
import sys
n = int(input())
lis = []
for i in range(n):
    lis.append(int(sys.stdin.readline()))
lis.sort()
for i in lis:
    print(i)
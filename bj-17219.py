import sys
a = sys.stdin.readline().split()
n, m = int(a[0]), int(a[1])
dic = {}
for i in range(n):
    a = sys.stdin.readline().split()
    dic[a[0]] = a[1]
for i in range(m):
    a = sys.stdin.readline().split()
    print(dic[a[0]])
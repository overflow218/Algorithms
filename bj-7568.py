import sys
n = int(input())
lis = []
for i in range(n):
    lis.append(list(map(int, sys.stdin.readline().split())))
for i in lis:
    print(len([j for j in lis if j[0] > i[0] and j[1] > i[1]]) + 1, end = " ")
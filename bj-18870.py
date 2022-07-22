import sys
n = int(input())
lis = list(map(int, sys.stdin.readline().split()))
check = {} 
for val, key in enumerate(sorted(list(set(lis)))):
    check[key] = val
for i in lis:
    print(check[i], end = " ")
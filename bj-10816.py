from collections import Counter
n = int(input())
lis = input().split()
m = int(input())
check = input().split()
lis = Counter(lis)
for c in check:
    print(lis[c], end = " ")
import sys
k = int(input())
lis = []
for i in range(k):
    tmp = int(sys.stdin.readline())
    if(tmp != 0):
        lis.append(tmp)
    else:
        lis.pop()
print(sum(lis))
import sys
lis = input().split()
m =  int(lis[1])
tree = list(map(int, sys.stdin.readline().split()))
ans = 0
low, high = 0, max(tree)
while(low <= high):
    mid = (low + high) // 2
    tmp = sum([i - mid for i in tree if i > mid])
    if(tmp >= m):
        low = mid + 1
        ans = mid
    else:
        high = mid - 1
print(ans)
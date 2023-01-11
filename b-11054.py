import sys
from bisect import bisect_left
n = int(sys.stdin.readline())
nums = list([int(i) for i in sys.stdin.readline().split(' ')])

front = [0] * n
back = [0] * n
lis = [nums[0]]
front[0] = 1

for i in range(1, n):
    if(lis[-1] < nums[i]):
        lis.append(nums[i])
        front[i] = len(lis)
        continue
    idx = bisect_left(lis, nums[i])
    lis[idx] = nums[i]
    front[i] = idx + 1

nums.reverse()
lis = [nums[0]]
back[0] = 1

for i in range(1, n):
    if(lis[-1] < nums[i]):
        lis.append(nums[i])
        back[i] = len(lis)
        continue
    idx = bisect_left(lis, nums[i])
    lis[idx] = nums[i]
    back[i] = idx + 1
back.reverse()

ans = max([i + j for i, j in zip(front, back)])
print(ans - 1)
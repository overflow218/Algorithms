lis = [0] * 1000100
n = int(input())
for i in range(1, n + 1):
    pSum = i + sum([int(k) for k in str(i)])
    lis[pSum] = i if lis[pSum] == 0 else lis[pSum]
print(lis[n])
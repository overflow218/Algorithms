n = int(input())
lis = [0, 1, 2]
for i in range(3, n + 1):
    lis.append((lis[-1] + lis[-2]) % 10007)
print(lis[n])